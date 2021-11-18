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
	int n;
	cin >> n;
	vvi adj(n);
	forn(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vb color(n, -1);
	vi p(n, -1);
	color[0] = 1;
	queue<int> q;
	for (auto x : adj[0])
	{
		p[x] = 0;
		q.push(x);
	}
	while (sz(q))
	{
		int f = q.front();
		q.pop();
		color[f] = 1 ^ color[p[f]];
		for (auto x : adj[f])
		{
			if (color[x] == -1)
			{
				p[x] = f;
				q.push(x);
			}
		}
	}
	int lg = 32 - __builtin_clz(n);
	vector<vector<int>> vals(lg);
	for (int i = 1; i <= n; i++)
		vals[31 - __builtin_clz(i)].push_back(i);
	int w = 0;
	int b = 0;
	forn(i, 0, n)
	{
		if (color[i])
		{
			w++;
		}
		else
		{
			b++;
		}
	}
	if (w > b)
	{
		swap(w, b);
		forn(i, 0, n)
		{
			color[i] = 1 ^ color[i];
		}
	}
	vi ans(n);
	for (int i = 0, j = 0, k = 0; k < lg; k++)
	{
		for (auto x : vals[k])
		{
			if (w >> k & 1)
			{
				while (!color[i])
					i++;
				ans[i++] = x;
			}
			else
			{
				while (color[j])
					j++;
				ans[j++] = x;
			}
		}
	}

	for (auto x : ans)
	{
		cout << x << " ";
	}
	cout << "\n";
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