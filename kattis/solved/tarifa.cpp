#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int x, n, xn, k;
    scanf("%d%d", &x, &n);
    xn = x*(n+1);
    while(scanf("%d", &k)==1){
        xn-=k;
    }
    printf("%d", xn);
}