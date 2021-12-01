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
using vb = vector<char>; //char faster
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
	cin >> n >> k;
	vi x(k);
	vi ttf(n, INF);
	queue<pii> q;
	forn(i, 0, k)
	{
		cin >> x[i];
		x[i]--;
		q.push({x[i], 0});
	}
	vvi adj(n);
	forn(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	while (!q.empty())
	{
		int node = q.front().fi;
		int d = q.front().se;
		q.pop();
		if (ttf[node] == INF)
		{
			ttf[node] = d;
			for (auto x : adj[node])
			{
				if (ttf[x] == INF)
				{
					q.push({x, d + 1});
				}
			}
		}
	}
	bool flag = false;
	q.push({0, 0});
	vb vi(n, false);
	while (!q.empty())
	{
		int node = q.front().fi;
		int d = q.front().se;
		q.pop();
		if (!vi[node])
		{
			vi[node] = 1;
			if (node != 0 && d < ttf[node] && sz(adj[node]) == 1)
			{
				flag = true;
				break;
			}
			for (auto x : adj[node])
			{
				if (!vi[x])
				{
					q.push({x, d + 1});
				}
			}
		}
	}
	if (flag)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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