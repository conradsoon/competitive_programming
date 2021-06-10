
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
const ll MOD = 1e9 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string temp;
	vvll dp(n, vll(n, 0));
	vector<vector<bool>> trap(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			trap[i][j] = (temp[j] == '*');
		}
	}
	if (trap[0][0] == false)
	{
		dp[0][0] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (trap[i][j] == false)
			{
				if (i - 1 >= 0)
				{
					dp[i][j] += dp[i - 1][j];
					dp[i][j] %= MOD;
				}
				if (j - 1 >= 0)
				{
					dp[i][j] += dp[i][j - 1];
					dp[i][j] %= MOD;
				}
			}
		}
	}
	cout << dp[n - 1][n - 1];
	return 0;
}