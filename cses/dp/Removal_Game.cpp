
#include <bits/stdc++.h>

using namespace std;

//TYPEDEFS
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

//MACROS
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = b; i >= a; i--)
//template ends

const ll INF = 1e17;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vll x(n + 1);
    vll pfx(n + 1);
    vvll dp(n + 1, vll(n + 1, -INF));
    REP(i, 1, n)
    {
        cin >> x[i];
        dp[1][i] = x[i];
        pfx[i] = pfx[i - 1] + x[i];
    }
    REP(i, 2, n)
    {
        REP(j, 1, n - i + 1)
        {
            dp[i][j] = pfx[j + i - 1] - pfx[j - 1] - min(dp[i - 1][j], dp[i - 1][j + 1]);
        }
    }
    cout << dp[n][1];
    return 0;
}