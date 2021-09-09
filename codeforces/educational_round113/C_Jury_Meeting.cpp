
#include <bits/stdc++.h>

using namespace std;

//TYPEDEFS
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

//MACROS
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = b; i >= a; i--)
const int MOD = 998244353;
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
	//FOR(i, 1, MX)
	for (int i = 1; i < MX; i++)
	{
		facs[i] = (facs[i - 1] * i);
	}
	facInvs[MX - 1] = inv(facs[MX - 1]);
	for (int i = MX - 1 - 1; i >= 0; i--)
	//F0Rd(i, MX - 1)
	{
		facInvs[i] = facInvs[i + 1] * (i + 1);
	}
}
//template ends
void solve()
{
	int n;
	cin >> n;
	vi a(n);
	for (auto &c : a)
	{
		cin >> c;
	}
	sort(a.begin(), a.end());
	ll mx = a.back();
	ll mx_count = a.end() - lower_bound(a.begin(), a.end(), mx);
	if (mx_count >= 2)
	{
		cout << facs[n] << "\n";
	}
	else
	{
		ll s_mx = *(--lower_bound(a.begin(), a.end(), mx));
		ll s_mx_count = upper_bound(a.begin(), a.end(), s_mx) - lower_bound(a.begin(), a.end(), s_mx);
		if (mx - s_mx > 1)
		{
			cout << "0\n";
		}
		else
		{
			mi ans = 1;
			ans *= s_mx_count;
			ans *= facs[s_mx_count];
			int _n = n - s_mx_count - 1;
			int _r = s_mx_count + 1 + 1;
			//https://math.stackexchange.com/questions/1079795/distributing-n-distinct-objects-in-r-distinct-boxes-when-order-matters
			ans *= facs[_n + _r - 1];
			ans *= facInvs[_r - 1];
			cout << ans << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	initFacs();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}