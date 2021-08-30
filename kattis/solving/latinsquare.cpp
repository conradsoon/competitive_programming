#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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
bool is_consistent(auto &sq, auto &pmt, int r1, int r2)
{
    for (int i = 0; i < sq[r1].size(); i++)
    {

        }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vvi sq(n, vi(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sq[i][j];
        }
    }
    vector<unordered_map<int, int>> pmt(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sq[i][j] != 0)
            {
                pmt[0][sq[i][j]] = j;
            }
        }
    }
    return 0;
}