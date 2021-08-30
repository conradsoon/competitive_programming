#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi fee(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fee[i];
    }
    vi cost(n, INF);
    cost[0] = 0;
    vvi dp(n + 1, vi(n, INF)); // [prev_jumps][square]
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
        }
        for (int j = 0; j < n; j++)
        {
            
        }
    }
    cout << cost[n - 1];
    return 0;
}