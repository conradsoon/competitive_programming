#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    while(getline(cin,word)){
        unordered_map<char,int> chars;
        long double perms = 1;
        int noc = word.length();
        for(char& c : word ){
            if(chars.count(c)==false){
                chars[c]=1;
            }
            else{
                chars[c]++;
            }
        }
        for(auto x : chars){
            for(int i = 1; i<=x.second; i++){
                perms/=i;
                perms*=noc;
                noc--;
            }
        }
        cout << fixed << perms << "\n";
    }
    return 0;
}