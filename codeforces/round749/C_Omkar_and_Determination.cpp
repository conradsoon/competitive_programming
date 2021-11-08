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
using vb = vector<bool>; //char faster
using vvb = vector<vector<bool>>;

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

void solve(int tc)
{
	int n, m;
	cin >> n >> m;
	vvb map(n, vb(m, false));
	forn(i, 0, n)
	{
		string temp;
		cin >> temp;
		forn(j, 0, m)
		{
			if (temp[j] == 'X')
			{
				map[i][j] = true;
			}
		}
	}
	vi f0(m / 2);
	for (int j = 0; j + 1 < m; j += 2)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (map[i + 1][j] && map[i][j + 1])
			{
				f0[j / 2]++;
			}
		}
	}
	vi pfx0(m / 2 + 1, 0);
	forn(i, 1, sz(pfx0))
	{
		pfx0[i] = pfx0[i - 1] + f0[i - 1];
	}
	vi f1((m - 1) / 2);
	for (int j = 1; j + 1 < m; j += 2)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (map[i + 1][j] && map[i][j + 1])
			{
				f1[(j - 1) / 2]++;
			}
		}
	}
	vi pfx1((m - 1) / 2 + 1);
	forn(i, 1, sz(pfx1))
	{
		pfx1[i] = pfx1[i - 1] + f1[i - 1];
	}
	int q;
	cin >> q;
	forn(i, 0, q)
	{
		//careful for single/double column reqs.
		ll sum = 0;
		int a, b;
		cin >> a >> b;
		a--, b--;
		//0
		int _a = a, _b = b;
		if (_a % 2)
		{
			_a++;
		}
		if (!(_b % 2))
		{
			_b--;
		}
		if (_b > _a)
		{
			sum += pfx0[(_b / 2) + 1] - pfx0[_a / 2];
		}
		//1
		_a = a, _b = b;
		if (!(_a % 2))
		{
			_a++;
		}
		if ((_b % 2))
		{
			_b--;
		}
		if (_b > _a)
		{
			sum += pfx1[((_b - 1) / 2) + 1] - pfx1[(_a - 1) / 2];
		}
		if (sum)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve(0);
	return 0;
}