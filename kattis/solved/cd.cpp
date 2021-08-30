#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, m, k, cdsold;
    unordered_set <int> cd;

    while((scanf("%d %d",&n,&m)>=1)){
        if(!n && !m){
            break;
        }
        cdsold=0;
        for (int i=0; i<n; i++){
            scanf("%d", &k);
            cd.insert(k);
        }
        for (int j=0; j<m; j++){
            scanf("%d", &k);
            if(cd.count(k)){
                cdsold++;
            }
        }
        printf("%d\n", cdsold);
    }
} 