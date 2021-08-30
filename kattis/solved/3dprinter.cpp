#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    n--;
    int i = 1;
    while((n)){
        n >>= 1;
        i++;
    }
    cout << i;
    return 0;
}