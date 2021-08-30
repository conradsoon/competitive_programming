#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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

//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        vi d(m);
        vector<unordered_map<int, int>> dp(m);
        for (int i = 0; i < m; i++)
        {
            cin >> d[i];
        }
        dp[0][d[0]] = d[0];
        for (int i = 1; i < m; i++)
        {
            for (auto ele : dp[i - 1])
            {
                int dist = ele.first;
                int max_ht = ele.second;
                int up_ht = dist + d[i];
                int dwn_ht = dist - d[i];
                if (up_ht >= 0)
                {
                    int max_up_ht = max(max_ht, up_ht);
                    if (dp[i].find(up_ht) == dp[i].end())
                    {
                        dp[i][up_ht] = max_up_ht;
                    }
                    dp[i][up_ht] = min(dp[i][up_ht], max_up_ht);
                }
                if (dwn_ht >= 0)
                {
                    int max_dwn_ht = max(max_ht, dwn_ht);
                    if (dp[i].find(dwn_ht) == dp[i].end())
                    {
                        dp[i][dwn_ht] = max_dwn_ht;
                    }
                    dp[i][dwn_ht] = min(dp[i][dwn_ht], max_dwn_ht);
                }
            }
        }
        int i = m - 1;
        if (dp[i].find(0) == dp[i].end())
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            string moves(m, 'x');
            int curr_ht = 0;
            int max_ht = dp[i][0];
            //check if i-- or --i
            moves[0] = 'U';
            while (i > 0)
            {
                int up_ht = curr_ht + d[i];
                int dwn_ht = curr_ht - d[i];
                if (up_ht >= 0)
                {
                    if (dp[i - 1].find(up_ht) != dp[i - 1].end() && dp[i - 1][up_ht] <= max_ht)
                    {
                        moves[i] = 'D';
                        max_ht = dp[i - 1][up_ht];
                        curr_ht = up_ht;
                        i--;
                        continue;
                    }
                }
                if (dwn_ht >= 0)
                {
                    if (dp[i - 1].find(dwn_ht) != dp[i - 1].end() && dp[i - 1][dwn_ht] <= max_ht)
                    {
                        moves[i] = 'U';
                        max_ht = dp[i - 1][dwn_ht];
                        curr_ht = dwn_ht;
                        i--;
                        continue;
                    }
                }
            }
            cout << moves << "\n";
        }
    }
    return 0;
}