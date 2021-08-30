#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, a, b;
    char q;
    cin >> n >> k;
    unordered_set<int> truebits;
    while(k--){
        cin >> q;
        if(q=='F'){
            cin >> a;
            if(truebits.count(a)){
                truebits.erase(a);
            }
            else{
                truebits.insert(a);
            }
        }
        else if(q=='C'){
            cin >> a >> b;
            int count = 0;
            for(const auto bit : truebits){
                if(bit>=a && bit <=b){
                    count++;
                }
            }
            cout << count << "\n";
        }
    }
    return 0;
}