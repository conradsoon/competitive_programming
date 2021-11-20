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
using vb = vector<char>; //char faster
using vvb = vector<vector<char>>;

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
	string s;
	cin >> s;
	int x = 1, y = 1;
	int s_x = 1, s_y = 1;
	int curr_x = 1, curr_y = 1;
	forn(i, 0, sz(s))
	{
		int _s_x = s_x, _s_y = s_y;
		if (s[i] == 'L')
		{
			curr_x--;
		}
		else if (s[i] == 'D')
		{
			curr_y++;
		}
		else if (s[i] == 'R')
		{
			curr_x++;
		}
		else if (s[i] == 'U')
		{
			curr_y--;
		}
		if (curr_x == 0)
		{
			_s_x++;
			x++;
			curr_x = 1;
		}
		else if (curr_x > x)
		{
			// _s_x--;
			x++;
			// curr_x++;
		}
		if (curr_y == 0)
		{
			_s_y++;
			y++;
			curr_y = 1;
		}
		else if (curr_y > y)
		{
			// _s_y--;
			y++;
			// curr_y++;
		}
		if (x <= m && y <= n)
		{
			s_x = _s_x;
			s_y = _s_y;
		}
		else
		{
			break;
		}
	}
	cout << s_y << " " << s_x << "\n";
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