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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output_b.txt", "w", stdout);
	vector<string> inp;
	string s;
	while (cin >> s)
	{
		inp.pb(s);
	}
	int n = sz(inp);
	int m = sz(inp[0]);
	vvb v(n, vb(m, 0));
	queue<pii> q;
	vi db;
	forn(i, 0, n)
	{
		forn(j, 0, m)
		{
			if (!v[i][j] && inp[i][j] != '9')
			{
				int c = 0;
				q.push({i, j});
				while (!q.empty())
				{
					int _i = q.front().fi;
					int _j = q.front().se;
					q.pop();
					if (!v[_i][_j] && inp[_i][_j] != '9')
					{
						v[_i][_j] = true;
						c++;
						if (_i - 1 >= 0)
						{
							q.push({_i - 1, _j});
						}
						if (_i + 1 < n)
						{
							q.push({_i + 1, _j});
						}
						if (_j - 1 >= 0)
						{
							q.push({_i, _j - 1});
						}
						if (_j + 1 < m)
						{
							q.push({_i, _j + 1});
						}
					}
				}
				db.pb(c);
			}
		}
	}
	sort(all(db));
	reverse(all(db));
	cout
		<< db[0] * db[1] * db[2];
	return 0;
}
