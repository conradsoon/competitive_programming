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
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi fpfx_t(n);
    vi fpfx_m(n);
    vi bpfx_t(n);
    vi bpfx_m(n);
    if (s[0] == 'M' || s[n - 1] == 'M')
    {
        cout << "NO\n";
    }
    else
    {
        bool flag = true;
        fpfx_t[0] = s[0] == 'T';
        fpfx_m[0] = s[0] == 'M';
        bpfx_t[n - 1] = s[n - 1] == 'T';
        bpfx_m[n - 1] = s[n - 1] == 'M';
        for (int i = 1; i < n; i++)
        {
            fpfx_t[i] = fpfx_t[i - 1] + (s[i] == 'T');
            fpfx_m[i] = fpfx_m[i - 1] + (s[i] == 'M');
        }
        for (int i = n - 2; i >= 0; i--)
        {
            bpfx_t[i] = bpfx_t[i + 1] + (s[i] == 'T');
            bpfx_m[i] = bpfx_m[i + 1] + (s[i] == 'M');
        }
        if (fpfx_t[n - 1] == 2 * fpfx_m[n - 1])
        {
            for (int i = 0; i < n; i++)
            {
                if (fpfx_m[i] > fpfx_t[i] || bpfx_m[i] > bpfx_t[i])
                {
                    flag = false;
                    break;
                }
            }
        }
        else
        {
            flag = false;
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
//template ends
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