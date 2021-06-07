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
const int INF = 1000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi a(n + 1);
    vi uo;
    uo.push_back(-1);
    vi o;
    o.push_back(-1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i])
        {
            o.push_back(i);
        }
        else
        {
            uo.push_back(i);
        }
    }
    vvi dp(o.size(), vi(uo.size(), INF));
    for (int i = 0; i <= uo.size(); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < o.size(); i++)
    {
        for (int j = i; j < uo.size(); j++)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + abs(o[i] - uo[j]), dp[i][j - 1]);
        }
    }
    cout << dp[o.size() - 1][uo.size() - 1];
    return 0;
}