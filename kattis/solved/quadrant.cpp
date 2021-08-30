#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf((x>>31)+1 ? ((y>>31)+1 ? "1": "4") : ((y>>31)+1 ? "2": "3"));
}