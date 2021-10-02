
#include <bits/stdc++.h>

using namespace std;

//TYPEDEFS
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

//MACROS
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = b; i >= a; i--)
//template ends
int maxbrl(vvi map, int r, int c, int n, int m)
{
	int d = 0;
	while (true)
	{
		d++;
		if (r - d < 0)
		{
			break;
		}
		if (c - d < 0)
		{
			break;
		}
		if (c + d >= m)
		{
			break;
		}
		if (!(map[r - d][c - d] && map[r - d][c + d]))
		{
			break;
		}
	}
	d--;
	return d;
}

void tick(vvi &map2, int r, int c, int d)
{
	REP(i, 0, d)
	{
		map2[r - i][c - i] = 1;
		map2[r - i][c + i] = 1;
	}
}

bool diff(vvi &map, vvi &map2, int n, int m)
{
	bool flag = false;
	REP(i, 0, n - 1)
	{
		if (flag)
		{
			break;
		}
		REP(j, 0, m - 1)
		{
			if (map[i][j] ^ map2[i][j])
			{
				flag = true;
				break;
			}
		}
	}
	return flag;
}
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vvi map(n, vi(m, 0));
	vvi map2(n, vi(m, 0));
	REP(i, 0, n - 1)
	{
		string temp;
		cin >> temp;
		REP(j, 0, m - 1)
		{
			if (temp[j] == '*')
			{
				map[i][j] = 1;
			}
		}
	}
	REP(i, 0, n - 1)
	{
		REP(j, 0, m - 1)
		{
			if (map[i][j])
			{
				int mx = maxbrl(map, i, j, n, m);
				if (mx >= k)
				{
					tick(map2, i, j, mx);
				}
			}
		}
	}
	if (!diff(map, map2, n, m))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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