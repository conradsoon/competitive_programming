
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<unsigned long long> vull;
typedef vector<vull> vvull;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
const int MAX_M = 2 * 1e5 + 20;
const ull MOD = 1e9 + 7;

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vull dp(MAX_M, 0);
    vull x(10, 0);
    x[0] = 1;
    dp[0] = 1;
    vull temp(10);
    for (int i = 1; i < MAX_M; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            temp[j] = x[j - 1];
        }
        temp[0] = x[9];
        temp[1] += x[9];
        for (int j = 0; j < 10; j++)
        {
            x[j] = temp[j] % MOD;
            dp[i] += temp[j];
            dp[i] %= MOD;
        }
    }

    while (t--)
    {
        string s;
        int k;
        cin >> s >> k;
        ull ans = 0;
        for (auto c : s)
        {
            ans += dp[k + (c - '0')];
            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}