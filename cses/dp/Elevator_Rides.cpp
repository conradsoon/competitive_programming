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
#define se second
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

void solve()
{
	int n;
	cin >> n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	vi w(n);
	vii dp(1 << n, {INF, INF});
	dp[0] = {0, 0};
	forn(i, 0, n)
	{
		cin >> w[i];
	}
	for (int m = 1; m < (1 << n); ++m)
	{
		for (int p = 0; p < n; p++)
		{
			if (m & (1 << p))
			{
				pii opt = dp[m ^ (1 << p)];
				opt.se += w[p];
				if (opt.se > x)
				{
					opt.fi++;
					opt.se = w[p];
				}
				setmin(dp[m], opt);
			}
		}
	}
	cout << (dp.back().se == 0 ? dp.back().fi : dp.back().fi + 1);
	return 0;
}