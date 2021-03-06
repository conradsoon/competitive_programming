
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
void solve()
{
	int n, x;
	cin >> n >> x;
	vvi dp(n + 1, vi(x + 1));
	vi h(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	vi s(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - h[i] >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
			}
		}
	}
	cout << dp[n][x] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}