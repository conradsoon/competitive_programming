#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int max = (int)floor(log2(n));
    cout << max+1 << "\n";
    int i = 1;
    int no;
    for(int i = 0; i <= max; i++){
        cout << (1<<i);
        if(i!=max){
            cout << " ";
        }
    }
    return 0;
}