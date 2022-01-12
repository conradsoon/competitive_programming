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
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
void solve(int tc)
{
	int n, l, k;
	cin >> n >> l >> k;
	vi d(n + 1);
	vi a(n + 1);
	forn(i, 0, n)
	{
		cin >> d[i];
	}
	forn(i, 0, n)
	{
		cin >> a[i];
	}
	d[n] = l;
	a[n] = 0;
	vvi dp(n + 1, vi(k + 1, INF));
	dp[0][0] = 0;
	forn(i, 0, n)
	{
		repn(j, 0, k)
		{
			if (dp[i][j] == INF)
			{
				continue;
			}
			for (int v = 0; i + (v + 1) <= n && v + j <= k; v++)
			{
				setmin(dp[i + v + 1][j + v], dp[i][j] + (a[i] * (d[i + v + 1] - d[i])));
			}
		}
	}
	int ans = INF;
	repn(j, 0, k)
	{
		setmin(ans, dp[n][j]);
	}
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}