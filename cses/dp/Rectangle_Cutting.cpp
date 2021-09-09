
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
#define REP(i, a, b) for (int i = a; i < b; i++)
//template ends
void solve()
{
	ll a, b;
	cin >> a >> b;
	if (a < b)
	{
		swap(a, b);
	}
	vvi dp(a + 1, vi(b + 1, 1e9));
	REP(i, 1, a + 1)
	{
		REP(j, 1, b + 1)
		{
			//vert cuts
			REP(k, 1, j / 2 + 1)
			{
				dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
			}
			//hori cuts
			REP(k, 1, i / 2 + 1)
			{
				dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
			}
			if (i == j)
			{
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[a][b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}