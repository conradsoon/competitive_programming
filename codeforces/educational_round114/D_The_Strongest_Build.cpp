
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
ll rate(vvi &a, vi &b)
{
	ll str = 0;
	REP(i, 0, a.size() - 1)
	{
		str += a[i][b[i]];
	}
	return str;
}
void solve()
{
	int n;
	cin >> n;
	vvi a(n);
	vi c(n);
	REP(i, 0, n - 1)
	{
		cin >> c[i];
		a[i].resize(c[i]);
		REP(j, 0, c[i] - 1)
		{
			cin >> a[i][j];
		}
	}
	int m;
	cin >> m;
	if (m == 0)
	{
		ll sum = 0;
		REP(i, 0, n - 1)
		{
			cout << a[i].size() << " ";
		}
		return;
	}
	queue<vector<int>> q;
	set<vi> banned;
	vvi b(m, vi(n));
	vi best_b(n, 0);
	ll best_str = -1;
	REP(i, 0, m - 1)
	{
		REP(j, 0, n - 1)
		{
			cin >> b[i][j];
			b[i][j]--;
		}
		banned.insert(b[i]);
	}
	REP(i, 0, m - 1)
	{
		REP(j, 0, n - 1)
		{
			if (b[i][j] - 1 >= 0)
			{
				//might have to check parents?
				b[i][j]--;
				if (banned.find(b[i]) == banned.end())
				{
					ll rnk = rate(a, b[i]);
					if (rnk > best_str)
					{
						best_str = rnk;
						best_b = b[i];
					}
				}
				b[i][j]++;
			}
		}
		REP(j, 0, n - 1)
		{
			if (b[i][j] + 1 < c[j])
			{
				//check kids
				b[i][j]++;
				if (banned.find(b[i]) == banned.end())
				{
					q.push(b[i]);
				}
				b[i][j]--;
			}
		}
	}
	while (!q.empty())
	{
		vi top = q.front();
		q.pop();
		ll rnk = rate(a, top);
		if (rnk > best_str)
		{
			best_str = rnk;
			best_b = top;
			REP(j, 0, n - 1)
			{
				if (top[j] + 1 < c[j])
				{
					//check kids
					top[j]++;
					if (banned.find(top) == banned.end())
					{
						q.push(top);
					}
					top[j]--;
				}
			}
		}
	}
	REP(i, 0, n - 1)
	{
		cout << best_b[i] + 1 << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}