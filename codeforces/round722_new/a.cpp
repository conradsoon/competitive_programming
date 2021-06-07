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
    map<int, int> m;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        m[temp]++;
    }
    if (m.size() == 1)
    {
        cout << "0\n";
    }
    else
    {
        cout << n - (*m.begin()).second << "\n";
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