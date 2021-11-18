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
#define forn(i, a, b) for (int i = a, end = (b); i < end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, end = (a); i >= end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, end = (b); i <= end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, end = (a); i >= end; i--)	 //[a,b] reversed
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
int n, m;				 // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vb visited;
vector<int> ans;
bool flag = false;
void dfs(int v)
{
	visited[v] = 0;
	for (int u : adj[v])
	{
		if (visited[u] == 0)
		{
			flag = true;
			return;
		}
		else if (visited[u] == -1)
		{
			dfs(u);
		}
	}
	visited[v] = 1;
	ans.push_back(v);
}

void topological_sort()
{
	visited.assign(n, -1);
	ans.clear();
	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == -1)
			dfs(i);
	}
	reverse(ans.begin(), ans.end());
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	visited.assign(n, -1);
	adj.assign(n, vi());
	forn(i, 0, m)
	{
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
	}
	forn(i, 0, n)
	{
		if (flag)
		{
			break;
		}
		if (visited[i] != 1)
		{
			dfs(i);
		}
	}
	if (flag)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		ans.clear();
		topological_sort();
		for (auto x : ans)
		{
			cout << x + 1 << " ";
		}
	}
	return 0;
}