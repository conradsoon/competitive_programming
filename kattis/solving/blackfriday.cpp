#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, int> o;
    vi o_arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> o_arr[i];
        o[o_arr[i]]++;
    }
    int max = 0;
    for (auto kv : o)
    {
        if (kv.second == 1 && kv.first > max)
        {
            max = kv.first;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (o_arr[i] == max)
        {
            cout << i + 1;
            break;
        }
    }
    if(max == 0){
        cout << "none";
    }
    return 0;
}