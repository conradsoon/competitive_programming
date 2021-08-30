#include <bits/stdc++.h>
#include <string>

using namespace std;
int main(){
    string chang, duan= "";
    cin >> chang;
    char c_old=NULL;
    for(char& c : chang){
        if(c!=c_old){
            duan += c;
        }
        c_old=c;
    }
    cout << duan;
}