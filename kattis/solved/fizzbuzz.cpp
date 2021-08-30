#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int x, y, n;
    scanf("%d%d%d", &x, &y, &n);
    for(int i=1; i<=n; i++){
        printf((i%x)?((i%y)?"%d\n":"Buzz\n"):((i%y)?"Fizz\n":"FizzBuzz\n"),i);
    }
}