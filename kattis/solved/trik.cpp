#include <bits/stdc++.h>
#include <string> 

using namespace std;
void swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main() 
{
    char m;
    char b[3]={1, 0, 0};
    int n=0;
    while(scanf("%c", &m) != EOF){
        if (m=='A'){
            swap(b[0],b[1]);
        }
        else if (m=='B'){
            swap(b[1],b[2]);
        }
        else if (m=='C'){
            swap(b[0],b[2]);
        }
    }
    while(!b[n]){
        n++;
    }
    printf("%d\n", n+1);
}