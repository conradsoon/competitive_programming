#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

const int INF = 1000000000;

int greedy(const vi &coins, vi &greedy_memo, int amt)
{
    if (greedy_memo[amt] == INF)
    {
        int max_coin = *(upper_bound(coins.begin(), coins.end(), amt) - 1);
        greedy_memo[amt] = greedy(coins, greedy_memo, amt - max_coin) + 1;
    }
    return greedy_memo[amt];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int max_amt = *(coins.end() - 1) + *(coins.end() - 2) - 1;
    vi dp(max_amt + 1, INF);
    vi greedy_memo(max_amt + 1, INF);
    dp[0] = 0;
    greedy_memo[0] = 0;
    for (int i = 1; i <= max_amt; i++)
    {
        for (auto c : coins)
        {
            if (i - c >= 0)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    bool is_canonical = true;
    for (int i = max_amt; i >= 0; i--)
    {
        if (dp[i] != greedy(coins, greedy_memo, i))
        {
            is_canonical = false;
            break;
        }
    }
    cout << (is_canonical ? "canonical" : "non-canonical");
    return 0;
}