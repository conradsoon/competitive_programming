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

void solve(int tc)
{
	int n, k;
	cin >> n >> k;
	/**
	string a = "";
	if (tc == 36)
	{
		a += to_string(n) + "-" + to_string(k) + ":";
		forn(i, 0, n - 1)
		{
			string b, c;
			cin >> b >> c;
			a += b;
			a += "-";
			a += c;
			a += ";";
		}
		cout << a << "\n";
		return;
	}
	**/
	vector<set<int>> adj(n);
	forn(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	vi onion(n);
	vector<bool> v(n, false);
	vi l;
	forn(i, 0, n)
	{
		if (sz(adj[i]) == 1)
		{
			l.pb(i);
			v[i] = true;
		}
	}
	int r = 0;
	while (!l.empty())
	{
		vi tl;
		for (auto i : l)
		{
			for (auto x : adj[i])
			{
				if (!v[x])
				{
					v[x] = true;
					tl.pb(x);
				}
			}
			onion[i] = r;
		}
		for (auto i : l)
		{
			for (auto x : adj[i])
			{
				adj[x].erase(i);
			}
			adj[i].clear();
		}
		l.clear();
		for (auto i : tl)
		{
			if (sz(adj[i]) <= 1)
			{
				l.pb(i);
			}
			else
			{
				v[i] = false;
			}
		}
		r++;
	}

	vi f(n, 0);
	vi pfx(n, 0);
	forn(i, 0, n)
	{
		f[onion[i]]++;
	}
	pfx[0] = f[0];
	forn(i, 1, n)
	{
		pfx[i] = pfx[i - 1] + f[i];
	}
	cout << n - pfx[min(n, k) - 1] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	rep(i, 1, t)
	{
		solve(i);
	}
	return 0;
}