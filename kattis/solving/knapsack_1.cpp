#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C, n;
    while(cin >> C >> n){
        int wt[n], val[n], dp[C+1] = {}, chosen[C] = {};
        for(int i = 0; i < n; i++){
            cin >> val[i] >> wt[i];
        }
        for(int i = wt[0]; i < C; i++){
            dp[i] = val[0];
            chosen[i] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = C; j>=wt[i]; j--){
                int test = dp[j-wt[i]] + val[i];
                if(dp[j] < test){
                    dp[j] = test;
                    chosen[j] = chosen[j-wt[i]]&(1<<i);
                }
            }
        }
        cout << __builtin_popcount(chosen[C]) << "\n";
        for(int i = 0; (chosen[C] >> i) > 0; i++){
             if(chosen[C] >> i){
                cout << i;
                if(chosen[C] >> i == 1){
                    cout << "\n";
                }
                else{
                    cout << " ";
                }
             }
        }
    }
    return 0;
}
