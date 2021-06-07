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
const int INF = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    vvll dp(n, vll(n, INF));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            dp[i][i + k] = s[i + k] - s[i] + min(dp[i + 1][i + k], dp[i][i + k - 1]);
        }
    }
    cout << dp[0][n - 1];
    return 0;
}