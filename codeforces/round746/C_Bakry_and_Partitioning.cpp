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
void solve()
{
	int n, k;
	cin >> n >> k;
	vi a(n);
	forn(i, 0, n)
	{
		cin >> a[i];
	}
	vvi adj(n);
	forn(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<bool> seen(n);
	vector<int> t(n);
	vector<int> d(n);
	vector<int> p(n, -1);
	stack<int> stk;
	stk.push(0);
	while (!stk.empty())
	{
		int tp = stk.top();
		if (seen[tp])
		{
			t[tp] ^= a[tp];
			if (p[tp] != -1)
			{
				t[p[tp]] ^= t[tp];
			}
			stk.pop();
		}
		else
		{
			seen[tp] = true;
			for (auto i : adj[tp])
			{
				if (!seen[i])
				{
					p[i] = tp;
					d[i] = d[tp] + 1;
					stk.push(i);
				}
			}
		}
	}
	bool can = false;
	if (t[0] == 0)
	{
		can = true;
	}
	else
	{
		if (2 <= k - 1)
		{
			pii b = {0, 0};
			forn(i, 1, n)
			{
				if (t[i] == t[0])
				{
					pii test = {d[i], i};
					setmax(b, test);
				}
			}
			if (b.se != 0)
			{
				int k = b.se;
				while (k != -1)
				{
					k = p[k];
					t[k] ^= t[b.se];
				}
				adj[b.se].erase(find(all(adj[b.se]), p[b.se]));
				adj[p[b.se]].erase(find(all(adj[p[b.se]]), b.se));
				vector<bool> seen2(n, false);
				queue<int> q;
				q.push(0);
				while (!q.empty())
				{
					int f = q.front();
					q.pop();
					seen2[f] = true;
					if (t[f] == t[b.se])
					{
						can = true;
					}
					for (auto i : adj[f])
					{
						if (!seen2[i])
						{
							q.push(i);
						}
					}
				}
			}
		}
	}
	if (can)
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
	while (t--)
	{
		solve();
	}
	return 0;
}