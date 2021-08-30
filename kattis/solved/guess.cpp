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

int main()
{
    int s = 1;
    int e = 1000;
    string input;
    while(true)
    {
        int guess = (s+e)/2;
        cout << guess << endl << flush;
        cin >> input;
        if(input == "lower"){
            e = guess-1;
        }
        else if (input == "higher"){
            s = guess+1;
        }
        else if (input == "correct"){
            break;
        }
    }
    return 0;
}