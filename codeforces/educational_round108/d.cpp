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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ull> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ull s = 0;
    for (int i = 0; i < n; i++)
    {
        s += (1ULL * a[i]) * (1ULL * b[i]);
    }
    ull m = s;
    vector<vector<ull>> dp(n, vector<ull>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = s;
    }
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = dp[i][i] - a[i] * b[i] - a[i + 1] * b[i + 1] + a[i] * b[i + 1] + a[i + 1] * b[i];
        m = max(dp[i][i + 1], m);
    }
    for (int k = 2; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            int j = i + k;
            dp[i][j] = dp[i + 1][j - 1] - a[i] * b[i] - a[j] * b[j] + a[i] * b[j] + a[j] * b[i];
            m = max(dp[i][j], m);
        }
    }
    cout << m;
    return 0;
}