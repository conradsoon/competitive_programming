#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long double> l = {NULL, 0};
    int n, maxl=1;
    while(cin >> n, n!=0){
        if(n>maxl){
            for(int i=maxl; i<n; i++){
                l.push_back(log(i+1)+l[i]);
            }
            maxl=n;
        }
        cout << setprecision(32) << exp(n*(1-log(n)) + l[n] - (0.5)*log(2*n*M_PI)) << "\n";
    }
    return 0;
}