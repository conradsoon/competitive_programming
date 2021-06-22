
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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x > y)
    {
        swap(x, y);
    }
    if (a > b)
    {
        swap(a, b);
    }
    if (a == b)
    {
        cout << x / a << "\n";
    }
    else
    {
        ld N = (1 / (pow((ld)a, 2) - pow((ld)b, 2))) * ((ld)a * x + (ld)b * -1 * y);
        ld M = (1 / (pow((ld)a, 2) - pow((ld)b, 2))) * ((ld)b * -1 * x + (ld)a * y);
        if (N >= 0 && M >= 0)
        {
            ll mx = 0;
            ll test_N = ceill(N);
            ll test_M = floorl(M);
            if (a * test_N + b * test_M <= x && b * test_N + a * test_M <= y)
            {
                mx = max(mx, test_N + test_M);
            }
            test_N = floorl(N);
            test_M = ceill(M);
            if (a * test_N + b * test_M <= x && b * test_N + a * test_M <= y)
            {
                mx = max(mx, test_N + test_M);
            }
            test_N = floorl(N);
            test_M = floorl(M);
            if (a * test_N + b * test_M <= x && b * test_N + a * test_M <= y)
            {
                mx = max(mx, test_N + test_M);
            }
            cout << mx << "\n";
        }
        else
        {
            cout << x / a << "\n";
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