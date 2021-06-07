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
    vvi adj(n + 1);
    unordered_set<int> gt2;
    unordered_set<int> lt2;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() > 2)
        {
            gt2.insert(i);
        }
        else if (adj[i].size() < 2)
        {
            lt2.insert(i);
        }
    }
    int n;
    int l;
    while (gt2.size() > 0)
    {
        n = *gt2.begin();
        l = *lt2.begin();
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