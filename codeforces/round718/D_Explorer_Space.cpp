
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
    int n, m, k;
    cin >> n >> m >> k;
    vvi hori(n, vi(m - 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            cin >> hori[i][j];
        }
    }
    vvi vert(n - 1, vi(m, 0));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vert[i][j];
        }
    }
    if (k % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "-1 ";
            }
            cout << "\n";
        }
    }
    else
    {
        vvi dp(n, vi(m, 0));
        vvi apply(n, vi(m, 0));
        int steps = k / 2;
        for (int s = 0; s < steps; s++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int mn = INF;
                    if (j + 1 < m)
                    {
                        mn = min(mn, dp[i][j + 1] + hori[i][j]);
                    }
                    if (j - 1 >= 0)
                    {
                        mn = min(mn, dp[i][j - 1] + hori[i][j - 1]);
                    }
                    if (i + 1 < n)
                    {
                        mn = min(mn, dp[i + 1][j] + vert[i][j]);
                    }
                    if (i - 1 >= 0)
                    {
                        mn = min(mn, dp[i - 1][j] + vert[i - 1][j]);
                    }
                    apply[i][j] = mn;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dp[i][j] = apply[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << 2 * dp[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}