#include <bits/stdc++.h>
#include <string>
using namespace std;
bool prefix(string a, string b){
    bool result = true;
    for(int i=0;i<min(a.length(),b.length());i++){
        if((int)a.at(i)!=(int)b.at(i)){
            result = false;
            break;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    while(cin >> k){
        vector<string> pnlist;
        string pn;
        bool coherent = true;
        int j = k;
        while(j--){
            cin >> pn;
            pnlist.push_back(pn);
        }
        sort(pnlist.begin(),pnlist.end(),greater<string>());
        for(int i=k-1;i>0;i--){
            if(prefix(pnlist[i],pnlist[i-1])){
                coherent=false;
                break;
            }
        }
        cout << (coherent?"YES\n":"NO\n");
    }
    return 0;
}