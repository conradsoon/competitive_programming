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
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

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
struct brk
{
	ll l;
	ll r;
	ll b;
};
bool operator<(const brk &lhs, const brk &rhs)
{
	if (lhs.b == rhs.b)
	{
		return lhs.l < rhs.l;
	}
	return lhs.b < rhs.b;
}
void solve(int tc)
{
	ll n, d;
	cin >> n >> d;
	vl a(n + 2);
	map<ll, ll> d2i;
	map<ll, ll> i2d;
	vector<brk> breaks;
	// disgusting hack
	a[0] = -2e10;
	a[n + 1] = 2e10;
	d2i[0] = a[0];
	i2d[a[0]] = 0;
	d2i[a[n + 1]] = n + 1;
	i2d[n + 1] = a[n + 1];
	repn(i, 1, n)
	{
		cin >> a[i];
		d2i[a[i]] = i;
		i2d[i] = a[i];
	}
	forn(i, 1, n + 2)
	{
		breaks.push_back({a[i - 1], a[i], a[i] - a[i - 1] - 1});
	}
	sort(all(breaks));
	ll min_break = breaks[0].b;
	// LOOK OUT FOR HTIS PART
	if (breaks[2].b == breaks[0].b)
	{
		cout << min_break << "\n";
		return;
	}
	// RMB ACCOUNT FOR MIN2
	ll max_break = breaks.back().b;
	if (breaks[0].r == breaks[1].l || breaks[0].l == breaks[1].r)
	{
		cout << min(breaks[2].b, min(breaks[0].b + 1 + breaks[1].b, (max_break - 1) / 2)) << "\n";
		return;
	}
	ll ans = min_break;
	ll lidx = d2i[breaks[0].l];
	ll ridx = d2i[breaks[0].r];
	if (lidx != 0)
	{
		ll new_break = i2d[lidx + 1] - i2d[lidx - 1] - 1;
		ans = max(ans, min(breaks[1].b, min(new_break, (max_break - 1) / 2)));
	}
	if (ridx != n + 1)
	{
		ll new_break = i2d[ridx + 1] - i2d[ridx - 1] - 1;
		ans = max(ans, min(breaks[1].b, min(new_break, (max_break - 1) / 2)));
	}
	cout << ans << "\n";
	return;
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