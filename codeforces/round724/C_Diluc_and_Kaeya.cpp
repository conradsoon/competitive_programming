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
    string s;
    cin >> s;
    int d = 0;
    int k = 0;
    map<pii, int> seen;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'D')
        {
            d++;
        }
        else if (s[i] == 'K')
        {
            k++;
        }
        pii p;
        if (d == 0)
        {
            p = {0, 1};
        }
        else if (k == 0)
        {
            p = {1, 0};
        }
        else
        {
            int gcd = __gcd(d, k);
            p = {d / gcd, k / gcd};
        }
        seen[p]++;
        cout << seen[p] << " ";
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