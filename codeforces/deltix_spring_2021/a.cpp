
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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < min(k, 1005); i++)
    {
        string new_s = s;
        if (s[1] == '1')
        {
            new_s[0] = '1';
        }
        if (s[n - 2] == '1')
        {
            new_s[n - 1] = '1';
        }
        for (int j = 1; j < n - 1; j++)
        {
            if (s[j - 1] + s[j + 1] == '1' + '0')
            {
                new_s[j] = '1';
            }
        }
        s = new_s;
    }
    cout << s << "\n";
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