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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> f(n);
        for (int i = 0; i < n; i++)
        {
            cin >> f[i];
        }
        vector<pair<int, int>> p(2);
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (f[i][j] == '*')
                {
                    p[c] = make_pair(i, j);
                    c++;
                    if (c == 2)
                    {
                        break;
                    }
                }
            }
            if (c == 2)
            {
                break;
            }
        }
        if ((p[0].first == p[1].first))
        {
            int i = (p[0].first + 1) % n;
            f[i][p[0].second] = '*';
            f[i][p[1].second] = '*';
        }
        else if ((p[0].second == p[1].second))
        {
            int j = (p[0].second + 1) % n;
            f[p[0].first][j] = '*';
            f[p[1].first][j] = '*';
        }
        else
        {
            f[p[0].first][p[1].second] = '*';
            f[p[1].first][p[0].second] = '*';
        }
        for (int i = 0; i < n; i++)
        {
            cout << f[i] << "\n";
        }
    }
    return 0;
}