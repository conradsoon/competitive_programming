
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
    int n;
    cin >> n;
}
const int INF = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vi c(n);
    for (auto &coin : c)
    {
        cin >> coin;
    }
    vi dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        for (auto coin : c)
        {
            if (coin + i < dp.size())
            {
                dp[coin + i] = min(dp[coin + i], dp[i] + 1);
            }
        }
    }
    if (dp[x] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << dp[x];
    }
    return 0;
}