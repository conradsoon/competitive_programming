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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vl dpp(n, 0);
	vl dpc(n, 0);
	vi p(n, -1);
	vector<vll> adj(n);
	forn(i, 0, m)
	{
		ll a, b;
		ll x;
		cin >> a >> b >> x;
		a--;
		b--;
		adj[a].pb({b, x});
	}
	int src = -1;
	forn(k, 0, n + 1)
	{
		src = -1;
		forn(i, 0, n)
		{
			for (auto e : adj[i])
			{
				if (dpp[i] != INFLL && dpp[i] + e.se < dpc[e.fi])
				{
					dpc[e.fi] = dpp[i] + e.se;
					p[e.fi] = i;
					src = e.fi;
				}
			}
		}
		swap(dpp, dpc);
	}
	bool flag1 = (src != -1);
	int idx;
	if (flag1)
	{
		forn(i, 0, n)
		{
			src = p[src];
		}
		cout << "YES\n";
		vi cycle;
		cycle.pb(src);
		idx = p[src];
		while (idx != src)
		{
			cycle.pb(idx);
			idx = p[idx];
		}
		cycle.pb(src);
		reverse(all(cycle));
		for (auto x : cycle)
		{
			cout << x + 1 << " ";
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}