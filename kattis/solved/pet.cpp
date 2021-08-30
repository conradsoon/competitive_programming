#include <bits/stdc++.h>

using namespace std;
int main() 
{
    int n = 1;
    int currscore;
    int maxscore=-1;
    int winner;
    int a, b, c, d;
    while(n<=5){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        currscore = a + b + c + d;
        if (currscore > maxscore){
            winner=n;
            maxscore = currscore;
        }
        n++;
    }
    printf("%d %d\n", winner, maxscore);
}