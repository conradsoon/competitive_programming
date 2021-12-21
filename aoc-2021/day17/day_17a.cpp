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
using vb = vector<char>; // char faster
using vvb = vector<vector<char>>;

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

int main()
{
	int xmn = 0;
	int xmx = 184 + 10;
	int ymn = -125 - 10;
	int ymx = 125 + 10;
	int lb = 138;
	int rb = 184;
	int ub = -71;
	int lob = -125;
	int c = 0;
	forn(i, xmn, xmx)
	{
		forn(j, ymn, ymx)
		{
			int _i = i;
			int _j = j;
			int x = 0;
			int y = 0;
			forn(k, 0, 10000)
			{
				x += _i;
				y += _j;
				if (_i > 0)
				{
					_i--;
				}
				_j--;
				if (x >= lb && x <= rb && y >= lob && y <= ub)
				{
					c++;
					break;
				}
				if (y < lob)
				{
					break;
				}
			}
		}
	}
	cout << c;
	return 1;
}
