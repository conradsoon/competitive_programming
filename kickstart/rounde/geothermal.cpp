#include "bits/stdc++.h"
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template <class T>
bool ckmin(T &a, const T &b)
{
	return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
	cerr << '{';
	__print(x.first);
	cerr << ", ";
	__print(x.second);
	cerr << '}';
}
template <typename T>
void __print(const T &x)
{
	int f = 0;
	cerr << '{';
	for (auto &i : x)
		cerr << (f++ ? ", " : ""), __print(i);
	cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
	__print(t);
	if (sizeof...(v))
		cerr << ", ";
	_print(v...);
}
#ifdef DEBUG
#define dbg(x...)                                                             \
	cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
	_print(x);                                                                \
	cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

void solve()
{
	ll N, M, K;
	cin >> N >> M >> K;
	N++;
	M++;
	ll X1, Y1, X2, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	X2++;
	Y2++;
	ll ans = (2) * ((Y2 - Y1 + K - 1) / K) + (2) * ((X2 - X1 + K - 1) / K);
	ll xv = (Y2 - Y1 + K - 1) / K;
	ll yv = (X2 - X1 + K - 1) / K;
	//ans += min((X2-X1-1)*xv + (Y2-Y1-1)*(X2-X1), (Y2-Y1-1)*yv + (X2-X1-1)*(Y2-Y1));
	ll xd = X2 - X1, yd = Y2 - Y1;

	ans += xd * yd - 1;

	ll xsq = (xd + K - 1) / K, ysq = (yd + K - 1) / K;
	ans -= xsq * ysq - 1;
	ans += xsq * (ysq - 1) + (xsq - 1) * ysq;

	bool found = false;
	if (X1 == 1)
	{
		found = true;
		ans -= xv;
	}
	if (X2 == N)
	{
		found = true;
		ans -= xv;
	}
	if (Y1 == 1)
	{
		found = true;
		ans -= yv;
	}
	if (Y2 == M)
	{
		found = true;
		ans -= yv;
	}

	if (!found)
	{
		ll val = min((X2 - 1 + K - 1) / K, (N - X1 + K - 1) / K) - yv;
		ckmin(val, min((Y2 - 1 + K - 1) / K, (M - Y1 + K - 1) / K) - xv);
		ans += val;
	}
	cout << ans << nl;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int T;
	cin >> T;
	FOR(i, 1, T + 1)
	{
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
