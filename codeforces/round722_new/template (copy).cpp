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
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    vi p(n);
    vi sz(n, 1);
    vi m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = -1;
        m[i] = a[i];
    }
    int max_sz = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sz[j] + 1 > sz[i])
            {
                bool strange = true;
                int it = j;
                int mx = max(m[j], a[i]);
                while (true)
                {
                    if (abs(a[i] - a[it]) < mx)
                    {
                        strange = false;
                        break;
                    }
                    it = p[it];
                    if (p[it] == -1)
                    {
                        break;
                    }
                }
                if (strange)
                {
                    sz[i] = sz[j] + 1;
                    p[i] = j;
                    m[i] = mx;
                }
            }
        }
        max_sz = max(max_sz, sz[i]);
    }
    cout << sz[n - 1] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}