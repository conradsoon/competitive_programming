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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vi c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int m;
    cin >> m;
    vi o(m);
    for (int i = 0; i < n; i++)
    {
        cin >> o[i];
    }

    int min_c = *min_element(c.begin(), c.end());
    int max_o = *max_element(o.begin(), o.end());
    int max_iter = (min_c + max_o - 1) / min_c;

    vvi dp(max_iter + 1, vi(max_o + 1, -2));
    vvi count(max_iter + 1, vi(max_o + 1, 0));
    dp[0][0] = -1;
    count[0][0] = 1;
    for (int i = 0; i <= max_iter; i++)
    {
        for (int j = 0; j <= max_o; j++)
        {
            if (dp[i][j] != -2)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j + c[k] <= max_o)
                    {
                        count[i + 1][j + c[k]] += count[i][j];
                        dp[i + 1][j + c[k]] = k;
                    }
                }
            }
        }
    }
    for (auto od : o)
    {
        ll sum_count = 0;
        ll no_iter;
        for (int i = 0; i <= max_iter; i++)
        {
            sum_count += count[i][od];
            if (dp[i][od] != -2)
            {
                no_iter = i;
            }
        }
        if (sum_count == 0)
        {
            cout << "Impossible\n";
        }
        else if (sum_count == 1)
        {
            int amt = od;
            while (amt > 0)
            {
                cout << dp[no_iter][amt] << " ";
                no_iter--;
                amt -= dp[no_iter][amt];
            }
        }
        else
        {
            cout << "Ambiguous\n";
        }
    }
    return 0;
}