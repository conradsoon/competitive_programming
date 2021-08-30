#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <vector>
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
#include <unordered_set>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

//template ends
vector<vector<int>> instructions;
vector<string> strs;

void coutRecurs(int n){
    cout << strs[n];
    for(auto i : instructions[n]){
        coutRecurs(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    unordered_set<int> head;
    strs.reserve(N + 1);
    instructions.resize(N+1, vector<int>());
    string input;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> input;
        strs[i] = input;
        head.insert(i);
    }
    int a, b;
    for (int i = 1; i < N; i++)
    {
        cin >> a >> b;
        instructions[a].push_back(b);
        head.erase(b);
    }
    coutRecurs(*head.begin());
    return 0;
}