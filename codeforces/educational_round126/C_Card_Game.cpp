#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using cd = complex<ld>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back // https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back
#define mp make_pair
#define sz(c) size(c)
#define all(c) begin(c), end(c)
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define fora(a, x) for (auto &a : x)
/**
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
**/
template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double EPS = 1e-9;
const char nl = '\n';

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define FAST_IO                            \
	std::ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                         \
	cout.tie(NULL)
#define yn(flag) ((flag) ? "YES" : "NO")
#define sgn(x) (((x) > 0) ? 1 : (((x) < 0) ? -1 : 0))

// credits to Geothermal
// adapted from https://codeforces.com/contest/1557/submission/125338963
const int MOD = 998244353;
const int MX = 100;

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

mi facs[MX];
mi facInvs[MX];

mi choose(mi _a, mi _b)
{
	ll a = (ll)_a, b = (ll)_b;
	if (b > a)
		return 0;
	if (a < 0)
		return 0;
	if (b < 0)
		return 0;
	mi cur = facs[a];
	cur = cur * facInvs[b];
	cur = cur * facInvs[a - b];
	return cur;
}

void initFacs()
{
	facs[0] = 1;
	// FOR(i, 1, MX)
	for (int i = 1; i < MX; i++)
	{
		facs[i] = (facs[i - 1] * i);
	}
	facInvs[MX - 1] = inv(facs[MX - 1]);
	for (int i = MX - 1 - 1; i >= 0; i--)
	// F0Rd(i, MX - 1)
	{
		facInvs[i] = facInvs[i + 1] * (i + 1);
	}
}
vmi a(MX);
vmi b(MX);

void solve(int tc)
{
	int n;
	cin >> n;
	cout << a[n] << " " << b[n] << " 1\n";
}

int main()
{
	FAST_IO;
	int t;
	cin >> t;
	initFacs();
	a[2] = 1;
	b[2] = 0;
	for (int i = 4; i < MX; i += 2)
	{
		a[i] = choose(i - 1, i / 2) + b[i - 2];
		b[i] = choose(i, i / 2) - 1 - a[i];
	}
	repn(i, 1, t) solve(i);
	return 0;
}