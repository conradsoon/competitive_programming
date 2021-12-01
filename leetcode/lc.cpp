#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<char>; //char faster
using vvb = vector<vector<char>>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)       //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)      //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)     //[a,b] reversed
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution
{
public:
    vector<vector<char>> r;
    vector<vector<char>> c;
    vector<vector<char>> g;
    vector<vector<char>> b;
    bool flag = false;
    int sq2r(int sq)
    {
        return sq / 9;
    }
    int sq2c(int sq)
    {
        return sq % 9;
    }
    int sq2g(int sq)
    {
        int gr = sq2r(sq) / 3;
        int gc = sq2c(sq) / 3;
        return gr * 3 + gc;
    }
    void f(int sq)
    {
        if (sq == 81)
        {
            flag = true;
            return;
        }
        if (flag == true)
        {
            return;
        }
        int ro = sq2r(sq);
        int co = sq2c(sq);
        int gr = sq2g(sq);
        if (b[ro][co] != '.')
        {
            f(sq + 1);
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (!r[ro][i] && !c[co][i] && !g[gr][i])
                {
                    b[ro][co] = '0' + i;
                    r[ro][i] = 1;
                    c[co][i] = 1;
                    g[gr][i] = 1;
                    f(sq + 1);
                    if (flag == true)
                    {
                        return;
                    }
                    b[ro][co] = '.';
                    r[ro][i] = 0;
                    c[co][i] = 0;
                    g[gr][i] = 0;
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        r.assign(9, vector<char>(10, 0));
        c.assign(9, vector<char>(10, 0));
        g.assign(9, vector<char>(10, 0));
        b = board;
        for (int i = 0; i < 81; i++)
        {
            int ro = sq2r(i);
            int co = sq2c(i);
            int gr = sq2g(i);
            char cr = b[ro][co];
            if (cr != '.')
            {
                r[ro][cr - '0'] = 1;
                c[co][cr - '0'] = 1;
                g[gr][cr - '0'] = 1;
            }
        }
        f(0);
        board = b;
    }
};
void solve()
{
    Solution sol;
    vvb board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    sol.solveSudoku(board);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}