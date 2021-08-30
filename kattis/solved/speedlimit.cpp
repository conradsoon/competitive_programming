#include <bits/stdc++.h>
#include <string> 

using namespace std;
int main() 
{
    int n, s, t_1, t_2, d;
    while(scanf("%d", &n), n!=-1){
        d=0;
        t_2=0;
        while(n--){
            scanf("%d %d", &s, &t_1);
            d+=s*(t_1-t_2);
            t_2 = t_1;
        }
        printf("%d miles\n", d);
    }
}