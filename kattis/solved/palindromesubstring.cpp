#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    while(cin >> word){
        queue<pair<int,int>> proc;
        set<string> palindromes;
        int n = word.length();
        for(int i = 0; i<n; i++){
            proc.push(make_pair(i,i));
        }
        for(int i = 0; i<n-1; i++){
            if(word[i] == word[i+1]){
                palindromes.insert(word.substr(i,2));
                proc.push(make_pair(i,i+1));
            }
        }
        while(!proc.empty()){
            pair<int,int> p = proc.front();
            if(p.first > 0 && p.second < n-1){
                p.first--; p.second++;
                if(word[p.first]==word[p.second]){
                    palindromes.insert(word.substr(p.first,p.second-p.first+1));
                    proc.push(make_pair(p.first,p.second));
                }
            }
            proc.pop();
        }
        for (string palin : palindromes){
            cout << palin << "\n";
        }
        cout << "\n";
    }
    return 0;
}