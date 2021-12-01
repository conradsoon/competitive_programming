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
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD = 1000000007;
const int MX = 210001;

struct mi
{
	ll v;
	explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v)
	{
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0)
			v += MOD;
	}
	friend bool operator==(const mi &a, const mi &b)
	{
		return a.v == b.v;
	}
	friend bool operator!=(const mi &a, const mi &b)
	{
		return !(a == b);
	}
	friend bool operator<(const mi &a, const mi &b)
	{
		return a.v < b.v;
	}

	mi &operator+=(const mi &m)
	{
		if ((v += m.v) >= MOD)
			v -= MOD;
		return *this;
	}
	mi &operator-=(const mi &m)
	{
		if ((v -= m.v) < 0)
			v += MOD;
		return *this;
	}
	mi &operator*=(const mi &m)
	{
		v = v * m.v % MOD;
		return *this;
	}
	mi &operator/=(const mi &m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p)
	{
		mi ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1)
				ans *= a;
		return ans;
	}
	friend mi inv(const mi &a)
	{
		assert(a.v != 0);
		return pow(a, MOD - 2);
	}

	mi operator-() const { return mi(-v); }
	mi &operator++() { return *this += 1; }
	mi &operator--() { return *this -= 1; }
	mi operator++(int)
	{
		mi temp;
		temp.v = v++;
		return temp;
	}
	mi operator--(int)
	{
		mi temp;
		temp.v = v--;
		return temp;
	}
	friend mi operator+(mi a, const mi &b) { return a += b; }
	friend mi operator-(mi a, const mi &b) { return a -= b; }
	friend mi operator*(mi a, const mi &b) { return a *= b; }
	friend mi operator/(mi a, const mi &b) { return a /= b; }
	friend ostream &operator<<(ostream &os, const mi &m)
	{
		os << m.v;
		return os;
	}
	friend istream &operator>>(istream &is, mi &m)
	{
		ll x;
		is >> x;
		m.v = x;
		return is;
	}
};

typedef vector<mi> vmi;
typedef pair<mi, mi> pmi;
typedef vector<pmi> vpmi;

int n, q, l;
mi mlt = 1000000;
vector<vector<int>> adj;
vector<vector<pair<mi, mi>>> prb;
vector<pair<mi, mi>> absprb;
mi one = 1;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

pair<mi, mi> compose(pair<mi, mi> v, pair<mi, mi> p)
{
	pair<mi, mi> ans;
	ans.fi = (p.fi) * v.fi + (1 - p.fi) * v.se;
	ans.se = (p.se) * v.fi + (1 - p.se) * v.se;
	return ans;
}
void dfs(int v, int p)
{
	tin[v] = ++timer;
	up[v][0] = p;
	if (v != 0)
	{
	}
	for (int i = 1; i <= l; ++i)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
		prb[v][i] = compose(prb[v][i - 1], prb[up[v][i - 1]][i - 1]);
	}

	for (int u : adj[v])
	{
		if (u != p)
			dfs(u, v);
	}

	tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = l; i >= 0; --i)
	{
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}
pair<mi, mi> prb2anc(int u, int anc)
{
	if (u == anc)
	{
		return {1, 0};
	}
	bool flag = true;
	pair<mi, mi> ans = {0, 0};
	//what if same?
	for (int i = l; i >= 0; --i)
	{
		if (!is_ancestor(up[u][i], anc))
		{
			if (flag)
			{
				flag = false;
				ans = prb[u][i];
			}
			else
			{
				compose(ans, prb[u][i]);
			}
			u = up[u][i];
		}
	}
	if (flag)
	{
		return prb[u][0];
	}
	else
	{
		return compose(ans, prb[u][0]);
	}
}
void solve(int tc)
{
	cin >> n >> q;
	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	prb.assign(n, vector<pair<mi, mi>>(l + 1));
	adj.resize(n, vi());
	mi rt;
	cin >> rt;
	rt /= mlt;
	prb[0][0].fi = 1;
	prb[0][0].se = 0;
	forn(i, 1, n)
	{
		int temp;
		cin >> temp;
		temp--;
		adj[temp].pb(i);
		cin >> prb[i][0].fi;
		prb[i][0].fi /= mlt;
		cin >> prb[i][0].se;
		prb[i][0].se /= mlt;
	}
	dfs(0, 0);
	vmi ans(q);
	forn(i, 0, q)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		int anc = lca(a, b);
		auto prbanc = prb2anc(anc, 0);
		auto a2anc = prb2anc(a, anc);
		auto b2anc = prb2anc(b, anc);
		mi pt = prbanc.fi * rt + (1 - rt) * prbanc.se;
		mi pf = 1 - pt;
		mi an = pt * (a2anc.fi * b2anc.fi) + pf * (a2anc.se * b2anc.se);
		ans[i] = an;
	}
	cout << "Case #" << tc << ": ";
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
	freopen("ts1_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}