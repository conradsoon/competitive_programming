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
const int MAXITR = 40;
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
	//check if half of as are the same
	for (auto kv : fa)
	{
		if (kv.second >= n / 2)
		{
			cout << -1 << "\n";
			return;
		}
	}
	ll ans = 1;
	forn(t, 0, MAXITR)
	{
		uniform_int_distribution<> distr(0, sz(a) - 1);
		ll a_idx = distr(rng);
		ll b_idx = distr(rng);
		while (b_idx == a_idx)
		{
			b_idx = distr(rng);
		}
		set<int> dvsrs;
		int d = abs(a[a_idx] - a[b_idx]);
		vi dv;
		dv.pb(1);
		for (auto p : pr)
		{
			if (d <= 1)
			{
				break;
			}
			int p_c = 0;
			while (!(d % p))
			{
				d /= p;
				p_c++;
			}
			int pwr = 1;
			int d_sz = sz(dv);
			forn(k, 0, p_c)
			{
				pwr *= p;
				forn(i, 0, d_sz)
				{
					dv.pb(pwr * dv[i]);
				}
			}
		}
		for (auto x : dv)
		{
			dvsrs.insert(x);
		}
		for (auto itr = dvsrs.rbegin(); itr != dvsrs.rend(); itr++)
		{
			if (check_ok(a, *itr))
			{
				setmax(ans, (ll)*itr);
				break;
			}
		}
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	const int N = 2e6 + 50;
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