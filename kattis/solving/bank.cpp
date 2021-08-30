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

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, T;
    cin >> N >> T;
    vector<pii> p;
    while(N--){
        int a, b;
        cin >> a >> b;
        p.push_back({a,b});
    }
    sort(p.begin(), p.end(), [](auto &left, auto &right){return left.second < right.second;});
    int sum = 0, time = -1;
    for(auto it = p.begin(); p.begin() != p.end(); it++){
        
    }
    while()
    return 0;
}