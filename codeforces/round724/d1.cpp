
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
    vector<ll> b(n);
    int peaks = 0; //unimod
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    if (n <= 1)
    {
        cout << "YES\n";
    }
    else
    {
        vector<ll> d(n - 1, 0);
        ll max_delta = 0;
        for (int i = 0; i < n - 1; i++)
        {
            d[i] = b[i + 1] - b[i];
            max_delta = max(max_delta, abs(d[i]));
        }
        for (int i = 1; i < n - 2; i++)
        {
            if (d[i] * d[i - 1] < 0)
            {
                peaks++;
            }
        }
        if (peaks > 1)
        {
            cout << "NO\n";
        }
        else
        {
            if (max_delta > 2)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
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