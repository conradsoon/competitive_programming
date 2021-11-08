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

pii edge = {-1, -1};
int n, m;
vvb mappu;
vvi dp;
int len;
bool cycle_found;
pii start;

pii succ(pii t)
{
	int i = t.fi;
	int j = t.se;
	if (mappu[t.fi][t.se] == 'R')
	{
		j++;
	}
	else if (mappu[t.fi][t.se] == 'U')
	{
		i--;
	}
	else if (mappu[t.fi][t.se] == 'L')
	{
		j--;
	}
	else if (mappu[t.fi][t.se] == 'D')
	{
		i++;
	}
	if (i < 1 || i > n)
	{
		return edge;
	}
	else if (j < 1 || j > m)
	{
		return edge;
	}
	else
	{
		return {i, j};
	}
}

// void dfs(vvb &mappu, vvi &dp, pii t)
// {
// 	if (dp[t.fi][t.se] >= 0)
// 	{
// 		return {{-2, -2}, dp[t.fi][t.se]};
// 	}
// 	else
// 	{
// 		if (succ(t) == edge)
// 		{
// 			return {{-1, -1}, 1};
// 		}
// 		if (dp[t.fi][t.se] == -2)
// 		{
// 			return {t, 0};
// 		}
// 		dp[t.fi][t.se] = -2; //checking
// 		pair<pii, int> ans = dfs(succ(t));
// 		ans.se++;
// 		if (ans.fi == t)
// 		{
// 			pii idx = t;
// 			while (succ(mappu, idx) != t)
// 			{
// 				idx = succ(mappu, idx);
// 				dp[idx.fi][idx.se] = ans.se;
// 			}
// 		}
// 		dp[t.fi][t.se] = ans.se;
// 		return {ans.fi, ans.se};
// 	}
// }

void solve(int tc)
{
	cin >> n >> m;
	mappu = vvb(n + 1, vb(m + 1));
	dp = vvi(n + 1, vi(m + 1, -1));
	repn(i, 1, n)
	{
		string s;
		cin >> s;
		repn(j, 1, m)
		{
			mappu[i][j] = s[j - 1];
		}
	}
	repn(i, 1, n)
	{
		repn(j, 1, m)
		{
			len = 0;
			cycle_found = false;
			pii idx = {i, j};
			while (true)
			{
				if (dp[idx.fi][idx.se] == -1)
				{
					dp[idx.fi][idx.se] = -2;
				}
				else
				{
					len += dp[idx.fi][idx.se];
					break;
				}
				idx = succ(idx);
				len++;
				if (idx == edge)
				{
					break;
				}
				if (dp[idx.fi][idx.se] == -2)
				{
					start = idx;
					cycle_found = true;
					break;
				}
			}
			idx = {i, j};
			while (len > 0 && dp[idx.fi][idx.se] < 0)
			{
				if (cycle_found && idx == start)
				{
					dp[idx.fi][idx.se] = len;
					while ((idx = succ(idx)) != start)
					{
						dp[idx.fi][idx.se] = len;
					}
					break;
				}
				dp[idx.fi][idx.se] = len;
				len--;
				idx = succ(idx);
			}
		}
	}
	pii t_ans = {-1, -1};
	int max_moves = 0;
	repn(i, 1, n)
	{
		repn(j, 1, m)
		{
			if (dp[i][j] > max_moves)
			{
				max_moves = dp[i][j];
				t_ans = {i, j};
			}
		}
	}
	cout << t_ans.fi << " " << t_ans.se << " " << max_moves << "\n";
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