#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long n, k;
    cin >> n >> k;
    if((n-1)>=2*k){
        cout << k + (n-1)%k + 1;
    }
    else{
        cout << n-1;
    }
    return 0;
}