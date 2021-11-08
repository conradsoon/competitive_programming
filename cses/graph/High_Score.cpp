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
	vl dpp(n, INFLL);
	vl dpc(n, INFLL);
	vector<vll> adj(n);
	vector<vll> adjb(n);
	dpp[0] = 0;
	dpc[0] = 0;
	forn(i, 0, m)
	{
		ll a, b;
		ll x;
		cin >> a >> b >> x;
		a--;
		b--;
		adj[a].pb({b, -x});
		adjb[b].pb({a, -x});
	}
	forn(k, 0, n + 1)
	{
		forn(i, 0, n)
		{
			for (auto e : adj[i])
			{
				setmin(dpc[e.fi], (dpp[i] == INFLL ? INFLL : dpp[i] + e.se));
			}
		}
		swap(dpp, dpc);
	}
	bool flag1 = false;
	bool flag2 = false;
	vb c(n, false);
	vb v(n, false);
	forn(i, 0, n)
	{
		if (dpc[i] != dpp[i])
		{
			c[i] = true;
			flag1 = true;
		}
	}
	if (flag1)
	{
		queue<int> q;
		q.push(n - 1);
		while (!q.empty())
		{
			int fr = q.front();
			q.pop();
			v[fr] = true;
			if (c[fr])
			{
				flag2 = true;
				break;
			}
			for (auto e : adjb[fr])
			{
				if (!v[e.fi])
				{
					q.push(e.fi);
				}
			}
		}
	}
	if (flag2)
	{
		cout << -1;
	}
	else
	{
		cout << -dpp[n - 1];
	}
	return 0;
}