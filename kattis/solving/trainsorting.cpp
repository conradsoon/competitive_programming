#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
//nlogn lis, but doesn't work and i can't be arsed to fix it
/**
vi lis(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    vi lis_list(n);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (d[i] < INF)
                ans = i;
        }
        lis_list[i] = j;
    }
    return lis_list;
}
**/

vi lis(vi const &a)
{
    vi dp(a.size(), 1);
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}
vi lds(vi const &a)
{
    vi dual = a;
    reverse(dual.begin(), dual.end());
    vi dual_ans = lis(dual);
    reverse(dual_ans.begin(), dual_ans.end());
    return dual_ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    vi li = lis(w);
    vi ld = lds(w);
    int max_l = 1;
    for (int i = 0; i < n; i++)
    {
        max_l = max(max_l, li[i] + ld[i] - 1);
    }
    cout << max_l;
    return 0;
}