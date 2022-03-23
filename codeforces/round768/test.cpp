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

ll solve(int n, int k)
{
	vb v(n, false);
	long long s = 0;
	if (k == n - 1)
	{
		// cout << -1 << "\n";
		return -1;
	}
	if (k == 0)
	{
		// cout << 0 << " " << n - 1 - k << "\n";
		v[0] = true;
		v[n - 1 - k] = true;
		s += 0 & (n - 1 - k);
	}
	else
	{
		// cout << 0 << " " << n - 1 - k << "\n";
		v[0] = true;
		v[n - 1 - k] = true;
		s += 0 & (n - 1 - k);
		// cout << k << " " << n - 1 << "\n";
		v[k] = true;
		v[n - 1] = true;
		s += k & (n - 1);
	}
	forn(i, 0, n / 2)
	{
		if (v[i])
		{
			continue;
		}
		// cout << i << " " << n - 1 - i << "\n";
		v[i] = true;
		v[n - 1 - i] = true;
		s += i & (n - 1 - i);
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 2; i < 16; i++)
	{
		int n = 1 << i;
		for (int j = 0; j < n - 1; j++)
		{
			if (solve(n, j) != j)
			{
				cout << n << " " << j << "\n";
				return 0;
			}
		}
	}
	return 0;
}