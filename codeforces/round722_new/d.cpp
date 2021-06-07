#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
//template ends
const int MOD = 998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi dp(n + 1, 0);
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = i; j < dp.size(); j += i)
        {
            dp[j]++;
            dp[j] = dp[j] % MOD;
        }
    }
    dp[0] = 1;
    dp[1] = 1;
    int S = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] += S;
        S += dp[i];
        S = S % MOD;
    }
    cout << dp[n];
    return 0;
}