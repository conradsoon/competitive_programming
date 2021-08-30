#include <bits/stdc++.h>
using namespace std;
int modexp(unsigned long a, unsigned long b, unsigned long n){
    unsigned long result = 1;
    vector<unsigned long> ap;
    ap.push_back(a%n);
    for(int i=0; b!=0; i++){
        if(i>0){
            ap[i]=(ap[i-1]*ap[i-1])%n;
        }
        if(b&1){
            result=((result)*(ap[i]))%n;
        }
        b>>=1;
    }
    return result;
}

int main()
{
    //Optimisations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Start
    unsigned long a, b, n=10000, result;
    char op;
    while(cin >> a >> op >> b){
        if(op=='+'){
            result = (a%n + b%n)%n;
        }
        else if(op=='*'){
            result = ((a%n)*(b%n))%n;
        }
        else if(op=='^'){
            result = modexp(a,b,n);
        }
        cout << result << "\n";
    }
    return 0;
}