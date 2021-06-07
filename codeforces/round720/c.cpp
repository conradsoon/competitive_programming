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
    vi p(n + 1, -1);
    int max_pos = -1;
    int res;
    for (int i = 1; i < n; i += 2)
    {
        cout << "? 1 " << i << " " << i + 1 << " " << n - 1 << "\n";
        cout.flush();
        cin >> res;
        if (res == n)
        {
            max_pos = i + 1;
            p[max_pos] = n;
            break;
        }
        else if (res == n - 1)
        {
            cout << "? 1 " << i + 1 << " " << i << " " << n - 1 << "\n";
            cout.flush();
            cin >>
                res;
            if (res == n)
            {
                p[i] = n;
                max_pos = i;
            }
        }
    }
    if (max_pos == -1)
    {
        max_pos = n;
        p[n] = n;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == max_pos)
        {
            continue;
        }
        else
        {
            cout << "? 2 " << i << " " << max_pos << " " << 1 << "\n";
            cout.flush();
            cin >> p[i];
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
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