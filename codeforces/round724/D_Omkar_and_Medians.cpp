
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
    vi b(n);
    set<int> seen;
    for (auto &i : b)
    {
        cin >> i;
    }
    if (n <= 2)
    {
        cout << "YES\n";
    }
    else
    {
        bool flag = false;
        set<int> seen;
        seen.insert(b[0]);
        seen.insert(b[1]);
        for (int i = 2; i < n; i++)
        {
            int r = max(b[i], b[i - 1]);
            int l = min(b[i], b[i - 1]);
            auto it = seen.upper_bound(l);
            if (it != seen.end())
            {
                int f = *it;
                if (f < r && f > l)
                {
                    flag = true;
                    break;
                }
            }
            seen.insert(b[i]);
        }
        if (flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
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