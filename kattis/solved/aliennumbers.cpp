#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vii;
typedef vector<vi> vvi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

//template ends
pair<map<char,int>, map<int,char>> digVal(string lang){
    map<char,int> string2Val;
    map<int,char> val2String;
    for(int i = 0; i<lang.length(); i++){
        string2Val[lang[i]]=i;
        val2String[i] = lang[i];
    }
    return {string2Val, val2String};
}
string translate(string sourceLang, string targLang, string input){
    auto sourceMaps = digVal(sourceLang);
    auto targMaps = digVal(targLang);
    auto ss2v = sourceMaps.first;
    auto tv2s = targMaps.second;
    string output = "";
    long val = 0;
    int power = 0;
    for(string::reverse_iterator it = input.rbegin(); it != input.rend(); it++){
        val += ss2v[*it]*pow(sourceLang.length(), power);
        power++;
    }
    power = 0;
    while(val > 0){
        output.push_back(tv2s[val%targLang.size()]);
        val /= targLang.size();
    }
    reverse(output.begin(),output.end());
    return output; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i = 1; i < T+1; i++){
        string alienNumber, sourceLang, targLang;
        cin >> alienNumber >> sourceLang >> targLang;
        string output = translate(sourceLang, targLang, alienNumber);
        cout << "Case #" << i << ": " << output << "\n";
    } 
    return 0;
}