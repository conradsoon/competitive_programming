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
	vector<vector<bool>> a(n, vector<bool>(5, false));
	forn(i, 0, n)
	{
		forn(j, 0, 5)
		{
			int temp;
			cin >> temp;
			a[i][j] = temp;
		}
	}
	bool flag = false;
	forn(i, 0, 4)
	{
		if (flag)
		{
			break;
		}
		forn(j, i + 1, 5)
		{
			int g1 = 0;
			int g2 = 0;
			int b = 0;
			forn(k, 0, n)
			{
				if (a[k][i] && a[k][j])
				{
					b++;
				}
				else if (a[k][i])
				{
					g1++;
				}
				else if (a[k][j])
				{
					g2++;
				}
			}
			if (g1 < g2)
			{
				swap(g1, g2);
			}
			if (g1 + g2 + b == n && g1 <= n / 2)
			{
				flag = true;
				break;
			}
		}
	}
	cout << (flag ? "YES\n" : "NO\n");
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