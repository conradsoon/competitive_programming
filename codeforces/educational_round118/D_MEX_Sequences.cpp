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
using vb = vector<char>; // char faster
using vvb = vector<vector<char>>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 998244353;
const int MAXN = 5 * 1e5 + 50;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vl pw2(MAXN);
void solve(int tc)
{
	int n;
	cin >> n;
	vi a(n);
	map<int, int>
		m;
	map<int, int> zbn;
	forn(i, 0, n)
	{
		cin >> a[i];
		m[a[i]]++;
		if (zbn.find(a[i]) == zbn.end())
		{
			zbn[a[i]] = m[0];
		}
	}
	ll ans = 0;
	ans += (pw2[m[0]] - 1);
	ans %= mod;
	ans += (pw2[m[1]] - 1);
	ans %= mod;
	ans += (pw2[m[0]] - 1) * (pw2[m[2]] - 1);
	ans %= mod;
	for (auto kv : m)
	{
		if (kv.fi != 0 && kv.fi != 2)
		{
			ans += (pw2[zbn[kv.fi]] - 1) * kv.se;
			ans %= mod;
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	pw2[0] = 1;
	for (int i = 1; i < sz(pw2); i++)
	{
		pw2[i] = pw2[i - 1] * 2;
		pw2[i] %= mod;
	}
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}