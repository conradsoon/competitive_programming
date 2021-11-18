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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
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
	vb v(n, false);
	vl d(n, INF);
	vl num(n, -1);
	num[0] = 1;
	vl minf(n, INFLL);
	vl maxf(n, -INFLL);
	minf[0] = 0;
	maxf[0] = 0;
	priority_queue<pll, vll, greater<pll>> pq;
	pq.push({d[0] = 0, 0});
	while (sz(pq))
	{
		int vert = pq.top().second;
		pq.pop();
		if (v[vert])
		{
			continue;
		}
		v[vert] = true;
		for (auto e : adj[vert])
		{
			ll alt = e.se + d[vert];
			if (alt == d[e.fi])
			{
				num[e.fi] = (num[e.fi] + num[vert]) % (ll)mod;
				setmin(minf[e.fi], minf[vert] + 1);
				setmax(maxf[e.fi], maxf[vert] + 1);
			}
			else if (alt < d[e.fi])
			{
				num[e.fi] = num[vert];
				minf[e.fi] = minf[vert] + 1;
				maxf[e.fi] = maxf[vert] + 1;
				pq.push({d[e.fi] = alt, e.fi});
			}
		}
	};
	cout << d[n - 1] << " " << num[n - 1] << " " << minf[n - 1] << " " << maxf[n - 1];
	return 0;
}