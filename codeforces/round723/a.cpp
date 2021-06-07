
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
    vi a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    while (true)
    {
        flag = true;
        for (int i = 0; i < 2 * n; i++)
        {
            if (a[(i - 1 + 2 * n) % (2 * n)] + a[(i + 1) % (2 * n)] == 2 * a[i])
            {
                swap(a[i], a[(i + 1) % (2 * n)]);
            }
        }
        for (int i = 0; i < 2 * n; i++)
        {
            if (a[(i - 1 + 2 * n) % (2 * n)] + a[(i + 1) % (2 * n)] == 2 * a[i])
            {
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
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