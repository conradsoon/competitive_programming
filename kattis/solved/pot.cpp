#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, k, exp, output = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &k);
        exp = k%10;
        output+=pow((k-exp)/10, exp);
    }
    printf("%d\n", output);
}