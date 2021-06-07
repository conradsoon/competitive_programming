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
int low(int k)
{
    return k * (k + 1) / 2;
}
int high(int n, int k)
{
    return n * k - (k - 1) * k / 2;
}
void solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int k = r - l + 1;
    vi p(n + 1);
    vi pp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        pp[i] = i;
    }
    for (int i = n; i > 0 && k > 0; i--)
    {
        if (high(i, k) >= s && (s - i) >= low(k - 1))
        {
            swap(p[l + k - 1], p[pp[i]]);
            pp[l + k - 1] = pp[i];
            pp[i] = l + k - 1;
            s -= i;
            k--;
        }
    }
    if (s == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
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