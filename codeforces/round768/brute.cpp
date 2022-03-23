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

vii solve(int n, int k)
{
	vii ans;
	if (k == n - 1)
	{
		ans.pb({-1, -1});
		return ans;
	}
	if (k == 0)
	{
		forn(i, 0, n / 2)
		{
			ans.pb({i, n - 1 - i});
		}
		return ans;
	}
	ans.pb({0, n - 1 - k});
	ans.pb({k, n - 1});
	forn(i, 0, n / 2)
	{
		if (i == 0 || i == n - 1 - k || i == k || i == n - 1 - k)
		{
			continue;
		}
		ans.pb({i, n - 1 - i});
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 16; i < 17; i++)
	{
		int n = 1 << i;
		for (int j = 0; j < n - 1; j++)
		{
			vii ans = solve(n, j);
			ll s = 0;
			vb v(n, false);
			if (sz(ans) != n / 2)
			{
				cout << n << " " << j << "\n";
				return 0;
			}
			for (auto p : ans)
			{
				s += p.fi & p.se;
				if (v[p.fi])
				{
					cout << n << " " << j << "\n";
					return 0;
				}
				v[p.fi] = true;
				if (v[p.se])
				{
					cout << n << " " << j << "\n";
					return 0;
				}
				v[p.se] = true;
			}
			if (s != j)
			{
				cout << n << " " << j << "\n";
				return 0;
			}
		}
		vii ans = solve(n, n - 1);
		if (ans[0] != mp(-1, -1))
		{
			cout << n << " " << n << "\n";
		}
	}
	return 0;
}