#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, k, c = 0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&k);
        if(!((k>>31)+1)){
            c++;
        }
    }
    printf("%d",c);
}