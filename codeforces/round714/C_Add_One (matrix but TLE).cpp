#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<unsigned long long> vull;
typedef vector<vull> vvull;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
const int MAX_POW = 18;
const ll MOD = 1e9 + 7;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<vvull> pwr(MAX_POW + 1, vvull(10, vull(10)));
    //initialise first power
    for (int i = 0; i < 9; i++)
    {
        pwr[0][i + 1][i] = 1;
    }
    pwr[0][0][9] = 1;
    pwr[0][1][9] = 1;
    //generate powers
    for (int i = 1; i < pwr.size(); i++)
    {
        pwr[i] = mod_matmul(pwr[i - 1], pwr[i - 1], MOD);
    }
    vector<vector<vvull>> basis()
    {
    }
    while (t--)
    {
        string s;
        int m;
        cin >> s >> m;
        vvull x(10, vull(1, 0));
        vvull RES(10, vull(1, 0));
        for (auto c : s)
        {
            x[c - '0'][0]++;
        }
        /**
        vvull RES_NAIVE(10, vull(1, 0));
        RES_NAIVE = x;
        for (int i = 0; i < m; i++)
        {
            RES_NAIVE = mod_matmul(pwr[0], RES_NAIVE, MOD);
        }
        **/
        RES = x;
        for (int i = 0; m > 0; m >>= 1, i++)
        {
            if (m & 1)
            {
                RES = mod_matmul(pwr[i], RES, MOD);
            }
        }
        vvull SUM(1, vull(10, 1));
        //cout << mod_matmul(SUM, RES_NAIVE, MOD)[0][0] << "\n";
        cout << mod_matmul(SUM, RES, MOD)[0][0] << "\n";
    }
    return 0;
}