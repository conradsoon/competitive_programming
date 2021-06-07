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
    string s;
    cin >> s;
    int i = 0;
    for (auto c : s)
    {
        if (c == '0')
        {
            i++;
        }
    }
    if (i == 1)
    {
        cout << "BOB\n";
    }
    else
    {
        if (i % 2 == 0)
        {
            cout << "BOB\n";
        }
        else
        {
            cout << "ALICE\n";
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