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
bool check_ok(vi &a, int num)
{
	bool flag = false;
	map<int, int> f;
	forn(i, 0, sz(a))
	{
		int res = a[i] % (num);
		if (res < 0)
		{
			res += num;
		}
		f[res]++;
	}
	for (auto kv : f)
	{
		if (kv.second >= sz(a) / 2)
		{
			flag = true;
		}
	}
	return flag;
}
void f(vll &pf, ll &mx, vi &a, ll i, ll fac)
{
	if (i == sz(pf))
	{
		if (fac > mx && check_ok(a, fac))
		{
			setmax(mx, fac);
		}
		return;
	}
	int pwr = fac;
	f(pf, mx, a, i + 1, pwr);
	repn(j, 1, pf[i].se)
	{
		pwr *= pf[i].fi;
		f(pf, mx, a, i + 1, pwr);
	}
}
void solve(vi &pr)
{
	int n;
	cin >> n;
	vi a(n);
	map<int, int> fa;
	forn(i, 0, n)
	{
		cin >> a[i];
		fa[a[i]]++;
	}
	sort(all(a));
	//check if half of as are the same
	for (auto kv : fa)
	{
		if (kv.second >= n / 2)
		{
			cout << -1 << "\n";
			return;
		}
	}
	auto stop = upper_bound(all(pr), a.back() + 5);
	vll pf;
	for (auto itr = stop; itr >= pr.begin(); itr--)
	{
		if (check_ok(a, *itr))
		{
			pf.pb({*itr, 1});
		}
	}
	ll ans = 1;
	for (auto &x : pf)
	{
		ll f = x.fi;
		ll i = 1;
		while (check_ok(a, f * x.fi))
		{
			f *= x.fi;
			x.se++;
		}
	}
	f(pf, ans, a, 0, 1);
	cout << ans << "\n";
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	const int N = 3e6;
	int lp[N + 1];
	vector<int> pr;
	for (int i = 2; i <= N; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
	repn(i, 1, t)
	{
		solve(pr);
	}
	return 0;
}