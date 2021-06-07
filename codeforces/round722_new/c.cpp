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
    int l, r;
    int u, v;
    vector<pair<ll, ll>> lr(n + 1);
    vvi g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> lr[i].first;
        cin >> lr[i].second;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int rt = 1; //arbitrary root at 1
    stack<int> stk;
    stk.push(rt);
    vector<bool> procd(n + 1, false);
    vector<ll> dpl(n + 1, 0);
    vector<ll> dpr(n + 1, 0);
    vi p(n + 1, -1);
    while (stk.size() != 0)
    {
        int i = stk.top();
        if (procd[i] == true)
        {
            for (auto it : g[i])
            {
                if (p[i] != it)
                {
                    dpl[i] += max(dpl[it] + abs(lr[i].first - lr[it].first), dpr[it] + abs(lr[i].first - lr[it].second));
                    dpr[i] += max(dpl[it] + abs(lr[i].second - lr[it].first), dpr[it] + abs(lr[i].second - lr[it].second));
                }
            }
            stk.pop();
        }
        else
        {
            for (auto it : g[i])
            {
                if (procd[it] == false)
                {
                    stk.push(it);
                    p[it] = i;
                }
            }
            procd[i] = true;
        }
    }
    cout << max(dpl[rt], dpr[rt]) << "\n";
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