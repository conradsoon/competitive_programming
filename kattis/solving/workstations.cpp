#include <iostream>
#include <string>
#include <vector>
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
struct researcher{
    int s;
    int e;
};
bool operator<(const researcher &lhs, const researcher &rhs){
    if(lhs.s == rhs.s){
        return lhs.s < rhs.s;
    }
    else{
        return lhs.a < rhs.a;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vii researchers;
    researchers.reserve(n);
    while(n--){
        int a, b;
        cin >> a >> b;
        researchers.push_back({a,b});
    }
    sort(researchers.begin(), researchers.end());
    return 0;
}