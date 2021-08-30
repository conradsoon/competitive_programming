#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    int time;
    char prob;
    string result;

    set<char> solved;
    map<char, int> wrong_times;
    int score = 0;
    while(true){
        getline(cin, input);
        if(input == "-1"){
            break;
        }
        istringstream iss(input, istringstream::in);
        iss >> time >> prob >> result;
        if(result == "right"){
            score += time;
            solved.insert(prob);
        }
        else{
            wrong_times[prob]++;
        }
    }
    for(auto p : solved){
        score += wrong_times[p] * 20;
    }
    cout << solved.size() << " " << score << "\n";
    return 0;
}