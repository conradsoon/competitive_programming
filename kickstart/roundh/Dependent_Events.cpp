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
vector<pair<mi, mi>> pos;
vector<mi> oc;
vector<mi> nooc;
mi one = 1;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
	tin[v] = ++timer;
	up[v][0] = p;
	if (v != 0)
	{
		pos[v].fi = oc[v] * pos[p].fi + nooc[v] * pos[p].se;
		pos[v].se = one - pos[v].fi;
	}
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

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

void preprocess(int root)
{
	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	dfs(root, root);
}
pair<mi, mi> apply(int i, pair<mi, mi> curr_prob)
{
	pair<mi, mi> ans;
	ans.fi = curr_prob.fi * oc[i] + curr_prob.se * nooc[i];
	ans.se = 1 - ans.fi;
	return ans;
}
void solve(int tc)
{
	cin >> n >> q;
	adj.resize(n, vi());
	pos.resize(n);
	oc.resize(n);
	nooc.resize(n);
	cin >> pos[0].fi;
	pos[0].fi /= mlt;
	pos[0].se = one - pos[0].fi;
	vmi ans;
	forn(i, 1, n)
	{
		int temp;
		cin >> temp;
		temp--;
		adj[temp].pb(i);
		cin >> oc[i];
		oc[i] /= mlt;
		cin >> nooc[i];
		nooc[i] /= mlt;
	}
	preprocess(0);
	forn(i, 0, q)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		int anc = lca(a, b);
		vi ap;
		vi bpv;
		ap.reserve(n + 5);
		bpv.reserve(n + 5);
		int _a = a;
		int _b = b;
		pair<mi, mi> anc_hap = {1, 0};
		pair<mi, mi> anc_no_hap = {0, 1};
		while (_a != anc)
		{
			ap.pb(_a);
			_a = up[_a][0];
		}
		reverse(all(ap));
		pair<mi, mi> a_anc_hap = anc_hap;
		pair<mi, mi> a_anc_no_hap = anc_no_hap;
		for (auto x : ap)
		{
			a_anc_hap = apply(x, a_anc_hap);
			a_anc_no_hap = apply(x, a_anc_no_hap);
		}
		while (_b != anc)
		{
			bpv.pb(_b);
			_b = up[_b][0];
		}
		reverse(all(bpv));
		pair<mi, mi> b_anc_hap = anc_hap;
		pair<mi, mi> b_anc_no_hap = anc_no_hap;
		for (auto x : bpv)
		{
			b_anc_hap = apply(x, b_anc_hap);
			b_anc_no_hap = apply(x, b_anc_no_hap);
		}
		mi ansp = pos[anc].fi * (a_anc_hap.fi * b_anc_hap.fi) + pos[anc].se * (a_anc_no_hap.fi * b_anc_no_hap.fi);
		ans.pb(ansp);
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
	int t;
	cin >> t;
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}