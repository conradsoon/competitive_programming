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
void dijkstra(int s, vector<vector<pii>> &adj, vector<int> &d, vector<int> &p)
{
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);
	vector<bool> u(n, false);

	d[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int v = -1;
		for (int j = 0; j < n; j++)
		{
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}

		if (d[v] == INF)
			break;

		u[v] = true;
		for (auto edge : adj[v])
		{
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to])
			{
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}
void solve(int tc)
{
	int n;
	cin >> n;
	vi a(n + 1);
	vi b(n + 1);
	repn(i, 1, n)
	{
		cin >> a[i];
	}
	repn(i, 1, n)
	{
		cin >> b[i];
	}
	vector<pii> adj(n + 1);
	repnr(i, 1, n)
	{
		adj[i] = {i + b[i] - a[i + b[i]], i + b[i]};
	}
	vi d(n + 1, INF);
	vi p(n + 1, -1);
	queue<pair<pii, int>> q;
	q.push(mp(mp(n, 0), -1));
	while (!q.empty())
	{
		int i = q.front().fi.fi;
		int di = q.front().fi.se;
		int pr = q.front().se;
		q.pop();
		if (di > d[i])
		{
			continue;
		}
		d[i] = di;
		p[i] = pr;
		if (i == 0)
		{
			break;
		}
		int idx = v;
		idx += b[idx];
		fornr(to, 1, )
		{
			if (d[to] == INF)
			{
				q.push(mp(mp(to, di + 1), i));
			}
			else
			{
				break;
			}
		}
	}
	if (p[0] == -1)
	{
		cout << "-1\n";
	}
	else
	{
		vi ans;
		ans.pb(0);
		int idx = 0;
		while ((idx = p[idx]) != n)
		{
			ans.pb(idx);
		}
		reverse(all(ans));
		cout << d[0] << '\n';
		for (auto x : ans)
		{
			cout << x << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve(-1);
	return 0;
}