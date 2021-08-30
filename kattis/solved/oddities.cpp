#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, k;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&k);
        printf("%d is %s\n", k, k&1? "odd": "even");
    }
}