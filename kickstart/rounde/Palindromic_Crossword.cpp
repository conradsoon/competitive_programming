#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
struct cell
{
	int i;
	int j;
	char c;
};

void solve(int tc)
{
	int n, m;
	cin >> n >> m;
	vector<set<int>> hori(n + 2, {0, m + 1});
	vector<set<int>> vert(m + 2, {0, n + 1});
	vector<vector<char>> grid(n + 2, vector<char>(m + 2));
	map<pii, vii> g;
	stack<cell> stk;
	ll counter = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == '#')
			{
				hori[i].insert(j);
				vert[j].insert(i);
			}
			else if (grid[i][j] != '.')
			{
				stk.push({i, j, grid[i][j]});
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//l-r
			if (grid[i][j] != '#')
			{
				int lb = *--hori[i].upper_bound(j);
				int rb = *hori[i].upper_bound(j);
				int j2 = rb + lb - j;
				if (j < j2)
				{
					g[{i, j}].push_back({i, j2});
					g[{i, j2}].push_back({i, j});
				}
				//u-d
				int up = *--vert[j].upper_bound(i);
				int db = *vert[j].upper_bound(i);
				int i2 = up + db - i;
				if (i < i2)
				{
					g[{i, j}].push_back({i2, j});
					g[{i2, j}].push_back({i, j});
				}
			}
		}
	}
	while (!stk.empty())
	{
		auto top = stk.top();
		stk.pop();
		for (auto pr : g[{top.i, top.j}])
		{
			if (grid[pr.first][pr.second] == '.')
			{
				counter++;
				grid[pr.first][pr.second] = top.c;
				stk.push({pr.first, pr.second, top.c});
			}
		}
	}
	cout << "Case #" << tc << ": " << counter << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << grid[i][j];
		}
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}
	return 0;
}