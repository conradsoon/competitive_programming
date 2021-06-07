
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
void solve()
{
    int n;
    cin >> n;
}
const ll INF = 1e14;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<ld> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<vector<ld>> sum_s(n, vector<ld>(n, 0));
    vector<vector<ld>> sum_s_square(n, vector<ld>(n, 0));
    vector<vector<ld>> mse(n, vector<ld>(n, 0));
    for (int i = 0; i < n; i++)
    {
        sum_s[i][i] = s[i];
        sum_s_square[i][i] = s[i] * s[i];
        mse[i][i] = 0;
    }
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            sum_s[i][i + k] = sum_s[i][i + k - 1] + s[i + k];
        }
    }
    vector<vector<ld>> dp(n + 1, vector<ld>(n, INF));
    return 0;
}