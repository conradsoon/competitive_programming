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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, end = (b); i < end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, end = (a); i >= end; i--) //[a,b) reversed
#define rep(i, a, b) for (int i = a, end = (b); i <= end; i++)		 //[a,b]
#define repr(i, a, b) for (int i = b, end = (a); i >= end; i--)		 //[a,b] reversed
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

/**
ll sum_of_prod(vll &a)
{
	ll ans = 0;
	if (sz(a) >= 3)
	{
		//https://math.stackexchange.com/questions/1775205/find-sum-of-product-of-all-possible-triplets-in-an-array-in-on
		ll sum = 0;
		ll sum_sq = 0;
		ll sum_cb = 0;
		forn(i, 0, sz(a))
		{
			ll temp = a[i].se;
			sum += temp;
			temp *= a[i].se;
			sum_sq += temp;
			temp *= a[i].se;
			sum_cb += temp;
		}
		ans += sum * sum * sum / 6;
		ans -= sum * sum_sq / 2;
		ans += sum_cb / 3;
	}
	return ans;
}
**/
void solve()
{
	ll n;
	cin >> n;
	vll a(n);
	map<ll, ll> t;
	map<ll, ll> d;
	forn(i, 0, n)
	{
		cin >> a[i].fi >> a[i].se;
		t[a[i].fi]++;
		d[a[i].se]++;
	}
	ll ans = n * (n - 1) * (n - 2) / 6;
	forn(i, 0, n)
	{
		ans -= (t[a[i].fi] - 1) * (d[a[i].se] - 1);
	}
	cout << ans << "\n";
	/**
	vll tv;
	for (auto kv : t)
	{
		tv.pb(kv);
	}
	vll dv;
	for (auto kv : d)
	{
		dv.pb(kv);
	}
	c += sum_of_prod(tv);
	c += sum_of_prod(dv);
	ll mn = min(sz(t), sz(d));
	c -= (mn) * (mn - 1) * (mn - 2) / 6;
	*/
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}