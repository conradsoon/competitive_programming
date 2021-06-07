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
const ll INF = 10000000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -INF));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j - 1] + a[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
            }
        }
    }
    for (int i = n; i >= 0; i--)
    {
        if (dp[n][i] >= 0)
        {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}