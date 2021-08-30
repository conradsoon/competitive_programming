#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string number;
    while(cin >> number && number != "END"){
        int i = 1;
        int n = number.length();
        while(i++, to_string(n).length() != n){
            n = to_string(n).length();
        }
        if(number=="1"){
            i--;
        }
        cout << i << "\n";
    }
    return 0;
}