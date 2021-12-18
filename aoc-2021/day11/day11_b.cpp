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
	freopen("output_a.txt", "w", stdout);
	vector<string> inp;
	string temp;
	while (cin >> temp)
	{
		inp.pb(temp);
	}
	int n = sz(inp);
	int m = sz(inp[0]);
	vvi st(n, vi(m));
	forn(i, 0, n)
	{
		forn(j, 0, m)
		{
			st[i][j] = inp[i][j] - '0';
		}
	}
	ll ans = 0;
	vvi nst;
	forn(k, 0, 10000)
	{
		nst = st;
		bool flag = true;
		int prev = nst[0][0];
		forn(_i, 0, n)
		{
			if (!flag)
			{
				break;
			}
			forn(_j, 0, m)
			{
				if (nst[_i][_j] != prev)
				{
					flag = false;
					break;
				}
				prev = nst[_i][_j];
			}
		}
		if (flag)
		{
			break;
		}
		ans++;
		queue<pii> fl;
		forn(i, 0, n)
		{
			forn(j, 0, m)
			{
				nst[i][j]++;
				fl.push({i, j});
			}
		}
		while (!fl.empty())
		{
			pii f = fl.front();
			fl.pop();
			if (nst[f.fi][f.se] > 9)
			{
				nst[f.fi][f.se] = 0;
				repn(_i, -1, 1)
				{
					repn(_j, -1, 1)
					{
						if (_i == 0 && _j == 0)
						{
							continue;
						}
						if (f.fi + _i >= 0 && f.fi + _i < n && f.se + _j >= 0 && f.se + _j < m)
						{
							if (nst[f.fi + _i][f.se + _j] == 0)
							{
								continue;
							}
							nst[f.fi + _i][f.se + _j]++;
							fl.push({f.fi + _i, f.se + _j});
						}
					}
				}
			}
		}
		swap(nst, st);
	}
	cout << ans;
	return 0;
}
