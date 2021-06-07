#include <bits/stdc++.h>

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

const int MAXINT = 1e7 + 10;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<ll> d_sum(MAXINT, 0);
    vi ans(MAXINT, 0);
    for (int i = 1; i < MAXINT; i++)
    {
        for (int j = i; j < MAXINT; j += i)
        {
            d_sum[j] += i;
        }
    }
    for (int i = 1; i < MAXINT; i++)
    {
        if (d_sum[i] < MAXINT)
        {
            if (ans[d_sum[i]] == 0)
            {
                ans[d_sum[i]] = i;
            }
        }
    }
    while (t--)
    {
        int c;
        cin >> c;
        if (ans[c] == 0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans[c] << "\n";
        }
    }
    return 0;
}