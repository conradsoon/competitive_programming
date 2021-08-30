#include <bits/stdc++.h>
#include <bitset>

using namespace std;
int msb(unsigned long n){
    int b = 0;
    while(n!=0){
        n >>= 1;
        b++;
    }
    return b;
}

int main(){
    unsigned long n, o;
    scanf("%lu", &n);
    int m = msb(n);
    bitset<64> in(n), out(0);
    for(int i=0; i<m; i++){
        out[i]=in[m-i-1];
    }
    printf("%lu", out.to_ulong());
}