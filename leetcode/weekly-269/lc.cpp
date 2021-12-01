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
vector<vector<int>> pfx;
int n;
int m;
int tc(int r, int a, int b)
{
    if (r < 0 || r >= n || a < 0 || a >= m || b < 0 || b >= m)
    {
        return -1;
    }
    int ans = 0;
    ans += pfx[r][b];
    if (a > 0)
    {
        ans -= pfx[r][a - 1];
    }
    return ans;
}
int countPyramids(vector<vector<int>> &grid)
{
    long long count = 0;
    n = sz(grid);
    m = sz(grid[0]);
    pfx.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        pfx[i][0] = grid[i][0];
        for (int j = 1; j < m; j++)
        {
            pfx[i][j] = pfx[i][j - 1] + grid[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int k = 1;
            int r = i;
            int a = j;
            int b = j;
            while (true)
            {
                r++;
                a--;
                b++;
                k += 2;
                int num = tc(r, a, b);
                if (num == k)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            k = 1;
            r = i;
            a = j;
            b = j;
            while (true)
            {
                r--;
                a--;
                b++;
                k += 2;
                int num = tc(r, a, b);
                if (num == k)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return count;
}
void solve()
{
    vvi grid = {{1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 0, 0, 1}};
    cout << countPyramids(grid);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}