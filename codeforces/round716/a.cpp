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
unordered_set<ll> sqrs;
void solve()
{
    int n;
    cin >> n;
    bool flag = false;
    int temp;
    ld sr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (sqrs.find(temp) == sqrs.end())
        {
            flag = true;
        }
    }
    cout << (flag ? "YES" : "NO") << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i < 10005; i++)
    {
        sqrs.insert(i * i);
    }
    while (t--)
    {
        solve();
    }
    return 0;
}