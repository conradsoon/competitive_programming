
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

const ll MOD = 1e9 + 7;
//template ends
void solve()
{
	int n;
	cin >> n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	vll dp(n + 15, 0);
	dp[0] = 1;
	for (int i = 0; i < dp.size() - 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			dp[i + j] += dp[i];
			dp[i + j] %= MOD;
		}
	}
	cout << dp[n];
	return 0;
}