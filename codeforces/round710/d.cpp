#include <bits/stdc++.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
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
    unordered_map<ll, ll> m;
    //https://codeforces.com/blog/entry/21853
    m.reserve(1 << 10);
    m.max_load_factor(0.25);
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        m[temp]++;
    }
    priority_queue<pair<ll, ll>> val;
    for (auto kv : m)
    {
        val.push({kv.second, kv.first});
    }
    //sort(val.begin(), val.end());
    pair<ll, ll> a, b;
    while (val.size() > 1)
    {
        a = val.top();
        a.first--;
        val.pop();
        b = val.top();
        b.first--;
        val.pop();
        n -= 2;
        if (a.first)
        {
            val.push(a);
        }
        if (b.first)
        {
            val.push(b);
        }
    }
    cout << n << "\n";
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