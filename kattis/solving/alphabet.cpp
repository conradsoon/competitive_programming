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
typedef unsigned long long int uint64;

//template ends
int cost(char a, char b){
    if (a==b){
        return 0;
    }
    else{
        return 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    string output = "abcdefghijklmnopqrstuvwxyz";
    cin >> input;
    vector<vector<int>> dp(input.length() + 1, vector<int>(output.length() + 1, 0));
    for (int i = 1; i <= output.length(); i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= input.length(); i++)
    {
        for (int j = 1; j <= output.length(); j++)
        {
            dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j]), dp[i - 1][j - 1] + cost(input[i],output[j]));
        }
    }
    cout << dp[input.length()][output.length()];
    return 0;
}