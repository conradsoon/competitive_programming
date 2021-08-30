#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
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
typedef unsigned long long int uint64;

//template ends
map<string, vector<int>> inv;
vector<string> shopping_list;
int path = 0;
//maybe optimise by cancelling everything if path found ==1?
void paths(int store, vector<string>::iterator it)
{
    if (true)
    {
        if (it == shopping_list.end())
        {
            path++;
        }
        else
        {
            string item = *it;
            for(auto i : inv[item]){
                if(i<=store){
                    paths(i, ++it);
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, M;
    cin >> N;
    cin >> K;
    int store;
    string item;
    while (K--)
    {
        cin >> store >> item;
        inv[item].push_back(store);
    }
    cin >> M;
    shopping_list.reserve(M);
    string input;
    while (M--)
    {
        cin >> input;
        shopping_list.push_back(input);
    }
    reverse(shopping_list.begin(), shopping_list.end());
    paths(N, shopping_list.begin());
    cout << ((path>1)?"ambiguous":(path==1?"unique":"impossible"));
    return 0;
}