#include <bits/stdc++.h>
#include <limits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    while(cin >> n >> m >> q){
        if(!(n|m|q)){
            break;
        }
        vector<vector<int>> fwmatrix(n,vector<int>(n,INT_MAX));
        for(int i = 0; i < n; i++){
            fwmatrix[i][i] = 0;
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            fwmatrix[u][v] = w;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(fwmatrix[i][k] != INT_MAX && fwmatrix[k][j] != INT_MAX){
                        int candidate = fwmatrix[i][k] + fwmatrix[k][j];
                        if(candidate < fwmatrix[i][j]){
                            fwmatrix[i][j] = candidate;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)    // Go through all possible sources and targets
                for(int k = 0; fwmatrix[i][j] != INT_MIN && k < n; k++)
                    if( fwmatrix[i][k] != INT_MAX && // Is there any path from i to k?
                        fwmatrix[k][j] != INT_MAX && // Is there any path from k to j?
                        fwmatrix[k][k] < 0){      // Is k part of a negative loop?

                        fwmatrix[i][j] = INT_MIN;   // If all the above are true
                                        // then the path from i to k is undefined
                    }
        for(int i = 0; i < q; i++){
            int a, b;
            cin >> a >> b;
            if(fwmatrix[a][b] == INT_MIN){
                cout << "-Infinity\n";
            }
            else if(a == b){
                cout << "0\n";
            }
            else if(fwmatrix[a][b] == INT_MAX){
                cout << "Impossible\n";
            }
            else{
                cout << fwmatrix[a][b] << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}