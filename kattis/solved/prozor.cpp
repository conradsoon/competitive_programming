#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, s, k;
    cin >> r >> s >> k;
    vector<vector<int>> prefix(r+1, vector<int>(s+1,0)); //shifted by one down right
    vector<string> picture;
    string input;
    while(cin >> input){
        picture.push_back(input);
    }
    for(int i = 1; i < r+1; i++){
        for(int j = 1; j<s+1; j++){
            prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
            if(picture[i-1][j-1] == '*'){
                prefix[i][j]++;
            }
        }
    }
    // find bottom right corner that gives best flies killed
    int bestVal = 0, bestX, bestY;
    for(int i = k; i<r+1; i++){
        for(int j = k; j<s+1; j++){
            int testVal = prefix[i-1][j-1] + prefix[i-1-(k-2)][j-1-(k-2)] - prefix[i-1][j-1-(k-2)] -prefix[i-1-(k-2)][j-1];
            if(testVal>bestVal){
                bestVal=testVal;
                bestX = i;
                bestY = j;
            }
        }
    }
    cout << bestVal << "\n";
    for(int i = k-1; i>=0; i--){
        picture[bestX-1-i][bestY-1] = '|';
        picture[bestX-1-i][bestY-1-(k-1)] = '|';
        picture[bestX-1][bestY-1-i] = '-';
        picture[bestX-1-(k-1)][bestY-1-i] = '-';
    }
    picture[bestX-1][bestY-1]='+';
    picture[bestX-1-(k-1)][bestY-1]='+';
    picture[bestX-1][bestY-1-(k-1)]='+';
    picture[bestX-1-(k-1)][bestY-1-(k-1)]='+';
    for(auto i:picture){
        cout << i << "\n";
    }
    return 0;
}