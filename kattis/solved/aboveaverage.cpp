#include <bits/stdc++.h>
#include <vector>
#include <iomanip>
#include <numeric>     
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin >> C;
    cin.ignore();
    while(C--){
        int N;
        cin >> N;
        vector<int> s;
        while(N--){
            int input;
            cin >> input;
            s.push_back(input);
        }
        sort(s.begin(),s.end());
        int sum = accumulate(s.begin(),s.end(), 0);
        int avg = sum/s.size()+1;
        int no = s.end() - lower_bound(s.begin(),s.end(), avg);
        cout << fixed;
        cout << setprecision(3);
        cout << (float(no)/float(s.size())*100) << "%" << "\n";
    }
    return 0;
}