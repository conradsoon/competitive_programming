#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    int n = 1;
    while(cin >> i){
        double digits = ceil(log10(3)+log10(1.5)*i);
        cout << "Case " << n << ": " << (unsigned long long)ceil(digits) << "\n";
        n++;
    }
    return 0;
}