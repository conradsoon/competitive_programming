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

void solve()
{
	int n;
	cin >> n;
	map<ll, ll> f;
	ll sum = 0;
	forn(i, 0, n)
	{
		ll temp;
		cin >> temp;
		sum += temp;
		f[temp]++;
	}
	vll a;
	for (auto kv : f)
	{
		a.pb(kv);
	}
	auto itr1 = a.begin();
	auto itr2 = a.end() - 1;
	ld k = (ld)sum / (ld)n;
	ll c = 0;
	while (itr1 <= itr2)
	{
		ld new_k = (ld)(sum - (*itr1).fi - (*itr2).fi) / (ld)(n - 2);
		if (abs(new_k - k) <= eps)
		{
			if (itr1 == itr2)
			{
				c += (*itr1).se * ((*itr1).se - 1) / 2;
			}
			else
			{
				c += (*itr1).se * (*itr2).se;
			}
			itr1++;
		}
		else if (new_k < k)
		{
			itr2--;
		}
		else if (new_k > k)
		{
			itr1++;
		}
	}
	cout << c << "\n";
	/**
	vl a(n);
	ll sum = 0;
	forn(i, 0, n)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(all(a));
	ld k = (ld)sum / (ld)n;
	ll c = 0;
	forn(i, 0, n)
	{
		fornr(j, i + 1, n)
		{
			ld new_avg = (ld)(sum - a[i] - a[j]) / (ld)(n - 2);
			if (abs(new_avg - k) <= eps)
			{
				c++;
			}
			else if (new_avg > k)
			{
				break;
			}
		}
	}
	cout << c << "\n";
	**/
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