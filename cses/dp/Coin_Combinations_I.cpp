
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
	ll n, x;
	cin >> n >> x;
	vll c(n);
	for (auto &k : c)
	{
		cin >> k;
	}
	vll dp(x + 15, 0);
	dp[0] = 1;
	for (ll i = 0; i < dp.size(); i++)
	{
		for (auto k : c)
		{
			if (i + k < dp.size())
			{
				dp[k + i] += dp[i];
				dp[k + i] %= MOD;
			}
		}
	}
	cout << dp[x];
	return 0;
}