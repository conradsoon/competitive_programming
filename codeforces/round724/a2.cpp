
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
const int INF = 1e9;
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    bool got_zero = false;
    bool got_negative = false;
    int mx = -INF;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (a[i] == 0)
        {
            got_zero = true;
        }
        else if (a[i] < 0)
        {
            got_negative = true;
        }
    }
    if (got_negative)
    {
        cout << "NO\n";
    }
    else
    {
        int gcd = __gcd(a[0], a[1]);
        for (int i = 2; i < n; i++)
        {
            gcd = __gcd(gcd, a[i]);
        }
        int size = 0;
        vi b;
        if (got_zero)
        {
            size++;
            b.push_back(0);
        }
        size += mx / gcd;
        if (size <= 300)
        {
            cout << "YES\n";
            cout << size << "\n";
            for (int i = gcd; i <= mx; i += gcd)
            {
                b.push_back(i);
            }
            for (int i = 0; i < b.size(); i++)
            {
                cout << b[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
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