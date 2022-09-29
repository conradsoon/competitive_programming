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
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

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
const int MAXN = 4000;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll fw[MAXN];
ll mf[MAXN];
void update(int x, int v)
{
	for (; x < MAXN; x += x & (-x))
		fw[x] += v;
}

int sum(int x)
{
	int res = 0;
	for (; x; x -= x & (-x))
		res += fw[x];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mf[1] = 1;
	mf[0] = 1;
	forn(i, 2, MAXN)
	{
		mf[i] = mf[i - 1] * i;
		mf[i] %= mod;
	}
	int _n, _m;
	cin >> _n >> _m;
	vi s(_n);
	forn(i, 0, _n)
	{
		cin >> s[i];
		update(s[i], 1);
	}
	vi t(_m);
	forn(i, 0, _m)
	{
		cin >> s[i];
	}
	ll ans = 0;
	forn(i, 0, _m)
	{
		// count less
		ll less = sum(s[i] - 1);
		// assign to same
	}
	return 0;
}