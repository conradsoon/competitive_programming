#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, a, b;
    char q;
    cin >> n >> k;
    vector<bool> mem(n+1,false);
    while(k--){
        cin >> q;
        if(q=='F'){
            cin >> a;
            mem[a]=mem[a]^1;
        }
        else if(q=='C'){
            cin >> a >> b;
            int count=0;
            for(int i=a; i<=b; i++){
                if(mem[i]==1){
                    count++;
                }
            }
            cout << count << "\n";
        }
    }
    return 0;
}