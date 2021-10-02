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
#define forn(i, a, b) for (int i = a; i < b; i++)		//[a,b)
#define fornr(i, a, b) for (int i = b - 1; i >= a; i--) //[a,b) reversed
#define rep(i, a, b) for (int i = a; i <= b; i++)		//[a,b]
#define repr(i, a, b) for (int i = b; i >= a; i--)		//[a,b] reversed
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

void solve()
{
	int n;
	cin >> n;
	vl a(n);
	forn(i, 0, n)
	{
		cin >> a[i];
	}
	vvl dp(2, vl(2005, INFLL));
	dp[0][0] = 0;
	forn(i, 0, n)
	{
		int r = i % 2;
		int rn = (i + 1) % 2;
		dp[rn] = vl(2005, INFLL);
		forn(j, 0, sz(dp[r]))
		{
			if (dp[r][j] != INFLL)
			{
				//goleft
				setmin(dp[rn][max(0LL, j - a[i])], dp[r][j] + a[i]);
				//gorjght
				if (j + a[i] < sz(dp[rn]))
				{
					setmin(dp[rn][j + a[i]], max(0LL, dp[r][j] - a[i]));
				}
			}
		}
	}
	ll ans = INFLL;
	forn(i, 0, sz(dp[n % 2]))
	{
		if (dp[n % 2][i] != INFLL)
		{
			setmin(ans, i + dp[n % 2][i]);
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
	while (t--)
	{
		solve();
	}
	return 0;
}