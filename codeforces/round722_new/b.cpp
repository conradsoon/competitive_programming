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
typedef unsigned long long int ull;
typedef long double ld;
//template ends
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto it = lower_bound(a.begin(), a.end(), 1);
    int count = it - a.begin();
    if (it != a.end())
    {
        bool flag = true;
        for (auto i = a.begin(); i < it - 1; i++)
        {
            if (abs(*i - *(i + 1)) < *it)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            count++;
        }
    }
    cout << count << "\n";
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