
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
    string s;
    cin >> s;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '0')
        {
            cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
            return;
        }
    }
    for (int i = n / 2; i < n; i++)
    {
        if (s[i] == '0')
        {
            cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
            return;
        }
    }
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
    return;
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