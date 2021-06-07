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
    vi p1(n + 1);
    p1[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p1[i];
    }
    if (is_sorted(p1.begin(), p1.end()))
    {
        cout << "0\n";
    }
    else if (p1[1] == n && p1[n] == 1)
    {
        cout << "3\n";
    }
    else if (p1[1] == 1 || p1[n] == n)
    {
        cout << "1\n";
    }
    else
    {
        cout << "2\n";
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