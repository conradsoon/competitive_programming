#include <bits/stdc++.h>
#include <string>
#include <algorithm>    // std::reverse


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin.peek()!=EOF){
        map<string,string> dysl;
        int maxchar = 0;
        string word;
        vector<string> words;
        while(cin.peek()!='\n' && cin.peek()!=EOF){
            cin >> word;
            cin.ignore(1);
            if(word.length()>maxchar){
                maxchar=word.length();
            }
            words.push_back(word);
        }
        for(string word : words){
            string key = word;
            reverse(key.begin(),key.end());
            int i = maxchar - word.length();
            while(i--){
                word.insert(0," ");
            }
            dysl.insert(make_pair(key,word));
        }
        for(auto entry : dysl){
            cout << entry.second << "\n";
        }
        if(cin.peek()=='\n'){
            cin.ignore(1);
            cout << "\n";
        }
    }
    return 0;
}