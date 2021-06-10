
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

const int INF = 1e9;
//template ends
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        for (auto c : s)
        {
            if (i - (c - '0') >= 0)
            {
                dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
            }
        }
    }
    cout << dp[n];
    return 0;
}