#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long n, pr=2, curr, no;
    int q;
    cin >> n >> q;
    vector<bool> composites;
    composites.resize(n+1);
    composites[0]=true;
    composites[1]=true;
    if(n>=2){
        while(pr*pr<=n){
            curr=pr*pr;
            while(curr<=n){
                composites[curr]=true;
                curr+=pr;
            }
            while(composites[pr+1]==true){
                pr++;
            }
            pr++;
        }
        cout << count(composites.begin(),composites.end(),false) << "\n";
    }
    else{
        cout << "0\n";
    }
    while(q--){
        cin >> no;
        cout << (composites[no]? "0" : "1") << "\n";
    }
    return 0;
}