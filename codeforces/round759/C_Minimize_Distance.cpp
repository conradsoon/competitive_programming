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
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(int tc)
{
	int n, k;
	cin >> n;
	cin >> k;
	vi x(n);
	vi xp;
	vi xn;
	forn(i, 0, n)
	{
		cin >> x[i];
	}
	forn(i, 0, n)
	{
		if (x[i] > 0)
		{
			xp.pb(x[i]);
		}
		else if (x[i] < 0)
		{
			xn.pb(-x[i]);
		}
	}
	sort(all(xp));
	reverse(all(xp));
	sort(all(xn));
	reverse(all(xn));
	ll ans = 0;
	if (sz(xp))
	{
		int q = sz(xp) / k;
		int r = sz(xp) % k;
		forn(i, 0, q)
		{
			ans += 2 * xp[i * k];
		}
		if (r)
		{
			ans += 2 * (*(xp.end() - r));
		}
	}
	if (sz(xn))
	{
		int q = sz(xn) / k;
		int r = sz(xn) % k;
		forn(i, 0, q)
		{
			ans += 2 * xn[i * k];
		}
		if (r)
		{
			ans += 2 * (*(xn.end() - r));
		}
	}
	ans -= max(sz(xn) ? xn[0] : 0, sz(xp) ? xp[0] : 0);
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}