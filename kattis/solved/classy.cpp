#include <bits/stdc++.h>
#include <string>
using namespace std;
//stringDELIMstringDELIMstring (so far)
/*
vector<string> tokenise(string str, char delim){
    vector<int> delimPos;
    vector<string> tokenised;
    for(int i=0;i<str.length();i++){
        if(str[i]==delim){
            delimPos.push_back(i);
        }
    }
    int n = delimPos.size();
    for(int i=0;i<n;i++){
        if(i==0){
            tokenised.push_back(str.substr(0,delimPos[i]));
        }
        if(i==n-1){
            tokenised.push_back(str.substr(delimPos[i]+1,str.length()-delimPos[i]));
        }
        else{
            tokenised.push_back(str.substr(delimPos[i]+1,delimPos[i+1]-delimPos[i]-1));
        }
    }
    return tokenised;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        while(n--){
            int k;
            map<int,set<string>>  society;
            while(k--){
                int layer = 10;
                int rank = 0;
                string name, str, dummy;
                vector<string> sprtdcls;

                //thank bwazefwost-san!
                istringstream ss(str);  
                getline(ss, name, ':'); // Get the name
                ss.ignore(); // Ignore the space after the ':'
                while(getline(ss, dummy, '-')) {
                    sprtdcls.push_back(dummy);
                }
                //Consider that there are 10 maximum specifiers, therefore 3^10 distinct classes. Assign each person a class according to this principle and sort.
                for(int i = sprtdcls.size()-1; i>0; i--){
                    if(sprtdcls[i]=="upper"){
                        rank += 2*pow(3,layer-1);
                    }
                    else if(sprtdcls[i]=="middle"){
                        rank += pow(3,layer-1);
                    }
                    layer--;
                }
                for(int layer = layer; layer>0; layer--){
                    rank += pow(3,layer-1);
                }
                society[rank].insert(name);
            }
            for(auto zhima : society){
                for(string name : zhima.second){
                    cout << name << "\n";
                }
            }
            cout << "==============================\n";
        }
    }
    return 0;
}