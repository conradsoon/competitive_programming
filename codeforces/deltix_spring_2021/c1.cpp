
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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); i++)
//template ends
void prl(vi &h, int d)
{
    for (int i = 1; i < d; i++)
    {
        cout << h[i] << ".";
    }
    cout << h[d] << "\n";
}
void solve()
{
    int n;
    cin >> n;
    int ln = 1;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vi h(1005, -1);
    int d = 0;
    while (ln <= n)
    {
        if (a[ln] == 1)
        {
            d++;
            h[d] = 1;
            prl(h, d);
            ln++;
        }
        else
        {
            while (h[d] + 1 != a[ln])
            {
                d--;
            }
            h[d] = a[ln];
            prl(h, d);
            ln++;
        }
    }
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