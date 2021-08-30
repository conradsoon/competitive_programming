#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;

//template ends
bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
    if(lhs.second == rhs.second) {
        return lhs.first < rhs.first;
    }
    return lhs.second < rhs.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vii ranges(N);
    int a, b;
    int mei = 0;//mutually exclusive intervals
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        ranges[i] = {a, b};
    }
    sort(ranges.begin(), ranges.end(), cmp);
    int counter = 1;
    int end = ranges[0].second;
    for(int i = 0; i < ranges.size(); i++){
        if(ranges[i].first > end){
            end = ranges[i].second;
            counter++;
        }
    }
    cout << counter; 
    return 0;
}