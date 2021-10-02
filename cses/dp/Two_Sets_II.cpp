
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
const int MOD = 1e9 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vvi dp(n + 1, vi(n * (n + 1) / 2 + 1, 0));
	dp[1][1] = 1;
	REP(i, 1, n - 1)
	{
		REP(j, 0, dp[i].size() - 1)
		{
			if (dp[i][j] != 0)
			{
				dp[i + 1][abs(j - (i + 1))] += dp[i][j];
				dp[i + 1][abs(j - (i + 1))] %= MOD;
				dp[i + 1][j + (i + 1)] += dp[i][j];
				dp[i + 1][j + (i + 1)] %= MOD;
			}
		}
	}
	cout << dp[n][0];
	return 0;
}