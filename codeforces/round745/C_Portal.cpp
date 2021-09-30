
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
void solve()
{
	int n, m;
	cin >> n >> m;
	vvi a(n + 1, vi(m + 1));
	vvi pfx(n + 1, vi(m + 1));
	REP(i, 1, n)
	{
		string s;
		cin >> s;
		REP(j, 1, m)
		{
			if (s[j - 1] == '1')
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}
	REP(i, 1, n)
	{
		REP(j, 1, m)
		{
			pfx[i][j] += pfx[i - 1][j];
			pfx[i][j] += pfx[i][j - 1];
			pfx[i][j] -= pfx[i - 1][j - 1];
			pfx[i][j] += a[i][j];
		}
	}
	cout << "TEst";
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