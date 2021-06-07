
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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << (n / 2) * 6 << "\n";
    for (int i = 1; i <= n; i += 2)
    {
        cout << "1 " << i << " " << i + 1 << "\n";
        cout << "1 " << i << " " << i + 1 << "\n";
        cout << "2 " << i << " " << i + 1 << "\n";
        cout << "1 " << i << " " << i + 1 << "\n";
        cout << "1 " << i << " " << i + 1 << "\n";
        cout << "2 " << i << " " << i + 1 << "\n";
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