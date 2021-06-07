#include <bits/stdc++.h>
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
void solve()
{
    int n;
    cin >> n;
    vi b(n + 2);
    for (int i = 0; i < n + 2; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (ll)b[i];
    }
    if (sum == b[n])
    {
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        ll x = sum + (ll)b[n] - (ll)b[n + 1];
        auto x_itr = b.begin();
        while (x_itr < b.end() - 1 && *x_itr != x)
        {
            x_itr++;
        }
        if (x_itr == b.end() - 1 || *x_itr != x)
        {
            cout << "-1\n";
        }
        else
        {
            for (auto itr = b.begin(); itr < x_itr; itr++)
            {
                cout << *itr << " ";
            }
            for (auto itr = x_itr + 1; itr < b.end() - 1; itr++)
            {
                cout << *itr << " ";
            }
            cout << "\n";
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