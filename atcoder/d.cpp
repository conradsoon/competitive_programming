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
    ull a, b, k;
    cin >> a >> b >> k;
    vector<vector<ull>> dp(a + 1, vector<ull>(b + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i >= 1)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j >= 1)
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    string s;
    int n = a + b;
    for (int i = 0; i < n; i++)
    {
        if (b >= 1 && dp[a - 1][b] < k)
        {
            k -= dp[a - 1][b];
            s.push_back('b');
            b--;
        }
        else
        {
            s.push_back('a');
            a--;
        }
    }
    cout << s;
    return 0;
}