#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define fi first
#define si second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, end = (b); i < end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, end = (a); i >= end; i--) //[a,b) reversed
#define rep(i, a, b) for (int i = a, end = (b); i <= end; i++)		 //[a,b]
#define repr(i, a, b) for (int i = b, end = (a); i >= end; i--)		 //[a,b] reversed
#define setmin(a, b) a = min(a, b)
#define setmax(a, b) a = max(a, b)
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct p
{
	ll s;
	ll e;
	ll r;
};
/**
bool operator<(const p &lhs, const p &rhs)
{
	if ()
	{
	}
	return lhs.e < rhs.e;
}
**/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<p> proj(n);
	map<int, int> comp;
	forn(i, 0, n)
	{
		cin >> proj[i].s;
		comp[proj[i].s];
		cin >> proj[i].e;
		proj[i].e++;
		comp[proj[i].e];
		cin >> proj[i].r;
	}
	int coord = 0;
	for (auto &kv : comp)
	{
		kv.second = coord;
		coord++;
	}
	vvi test(sz(comp));
	forn(i, 0, sz(proj))
	{
		proj[i].s = comp[proj[i].s];
		proj[i].e = comp[proj[i].e];
		test[proj[i].e].pb(i);
	}
	vl dp(sz(comp), 0);
	forn(j, 1, sz(dp))
	{
		dp[j] = dp[j - 1];
		/**
		if (j > 0)
		{
			dp[j] = dp[j - 1];
		}
		**/
		for (auto k : test[j])
		{
			dp[j] = max(dp[j], dp[proj[k].s] + proj[k].r);
			//setmax(dp[j], proj[k].s + proj[k].r);
		}
	}
	cout << dp.back() << "\n";

	return 0;
}