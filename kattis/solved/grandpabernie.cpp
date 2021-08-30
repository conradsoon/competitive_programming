#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<string, vector<int>> trips;
    while(n--){
        int year;
        string name;
        cin >> name >> year;
        trips[name].push_back(year);
    }
    for(auto& data : trips){
        sort(data.second.begin(),data.second.end());
    }
    int q;
    cin >> q;
    while(q--){
        int time;
        string name;
        cin >> name >> time;
        cout << trips[name][time-1] << "\n";
    }
    return 0;

}