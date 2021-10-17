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
using vb = vector<char>;
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
	vi p(n, -1);
	vvi adj(n);
	forn(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	queue<int> q;
	q.push(0);
	bool flag = false;
	p[0] = -2;
	while (!q.empty())
	{
		if (flag)
		{
			break;
		}
		int f = q.front();
		q.pop();
		for (auto x : adj[f])
		{
			if (p[x] == -1)
			{
				q.push(x);
				p[x] = f;
			}
			if (x == n - 1)
			{
				flag = true;
				break;
			}
		}
	}
	if (flag)
	{
		vi ans;
		int idx = n - 1;
		ans.pb(n - 1);
		while ((idx = p[idx]) != -2)
		{
			ans.pb(idx);
		}
		reverse(all(ans));
		cout << sz(ans) << "\n";
		for (auto x : ans)
		{
			cout << x + 1 << " ";
		}
	}
	else
	{
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}