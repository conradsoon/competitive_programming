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
    string a, b;
    cin >> a;
    cin >> b;
    if (a.length() < b.length())
    {
        swap(a, b);
    }                                                          //ensures a is longer than b
    a = string(b.length(), '*') + a + string(b.length(), '*'); //padding
    int maxn = 0;
    for (int i = 0; i < a.length() - b.length(); i++)
    {
        int test = 0;
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i + j] != b[j])
            {
                test = 0;
            }
            else
            {
                test++;
                maxn = max(maxn, test);
            }
        }
    }
    cout << (a.length() - (2 * b.length()) - maxn) + (b.length() - maxn) << "\n";
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