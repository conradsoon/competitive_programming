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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output_a.txt", "w", stdout);
	vector<string> inp;
	string s;
	while (cin >> s)
	{
		inp.pb(s);
	}
	int _n = sz(inp);
	int _m = sz(inp[0]);
	int n = sz(inp) * 5;
	int m = sz(inp[0]) * 5;
	vvl a(n, vl(m));
	vvl dp(n, vl(m, -INFLL));
	forn(i, 0, n)
	{
		forn(j, 0, m)
		{
			a[i][j] = ((inp[i % _n][j % _m] - '0') + (i / _n) + (j / _m));
			if (a[i][j] > 9)
			{
				a[i][j] = a[i][j] % 10 + 1;
			}
			a[i][j] = -a[i][j];
		}
	}
	priority_queue<pair<int, pii>> pq;
	pq.push({0, {0, 0}});
	pii dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	while (!pq.empty())
	{
		int d = pq.top().fi;
		pii pos = pq.top().se;
		pq.pop();
		if (pos == mp(n - 1, m - 1))
		{
			cout << -d;
			return 1;
		}
		if (d > dp[pos.fi][pos.se])
		{
			dp[pos.fi][pos.se] = d;
			for (auto di : dir)
			{
				pii c = {di.fi + pos.fi, di.se + pos.se};
				if (c.fi >= 0 && c.fi < n && c.se >= 0 && c.se < m)
				{
					pq.push({d + a[c.fi][c.se], {c.fi, c.se}});
				}
			}
		}
	}
	return 1;
}
