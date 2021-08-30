#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C, n;
    while (cin >> C >> n)
    {
        vector<int>  wt(n+1), val(n+1);
        vector<vector<int>>  dp(n+1,vector<int>(C+1, 0));
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i] >> wt[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = C; j >= wt[i]; j--)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - wt[i]] + val[i]);
            }
        }

        vector<int> elements;
        int currWt = C;
        for(int i = n; i > 0 && currWt  > 0; i--){
            if(dp[i][currWt] == dp[i-1][currWt]){
                continue;
            }
            else{
                elements.push_back(i);
                currWt -= wt[i];
            }
        }
        cout << elements.size() << "\n";
        for(auto i : elements){
            cout << i-1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
