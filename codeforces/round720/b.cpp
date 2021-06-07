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
    vi a(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto min_itr = min_element(a.begin(), a.end());
    cout << n - 1 << "\n";
    for (auto itr = a.begin(); itr < a.end(); itr++)
    {
        if (itr == min_itr)
        {
            continue;
        }
        else
        {
            cout << min_itr - a.begin() + 1 << " " << itr - a.begin() + 1 << " " << *min_itr << " " << *min_itr + abs(min_itr - itr) << "\n";
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