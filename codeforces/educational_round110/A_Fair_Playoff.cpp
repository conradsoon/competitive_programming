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
    vi a(4);
    vi sort_a(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
        sort_a[i] = a[i];
    }
    sort(sort_a.begin(), sort_a.end());
    if (max(a[0], a[1]) + max(a[2], a[3]) == sort_a[3] + sort_a[2])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}