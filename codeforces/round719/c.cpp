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
        if (n == 2)
        {
            cout << "-1\n";
        }
        else
        {
            int x = 1;
            int p = (n * n + 2 - 1) / 2;
            int m = -(p - 1);
            for (int i = 1; i <= n * n; i++)
            {
                cout << x << " ";
                if (i % 2 == 1)
                {
                    x += p;
                }
                else
                {
                    x += m;
                }
                if (i % n == 0)
                {
                    cout << "\n";
                }
            }
        }
    }
    return 0;
}