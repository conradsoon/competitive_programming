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
const ll INF = 1e18;
//https://cp-algorithms.com/graph/dijkstra.html
void dijkstra(ll s, vector<ll> &d, vector<ll> &p, vector<vector<pair<ll, ll>>> &adj)
{
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (ll i = 0; i < n; i++)
    {
        ll v = -1;
        for (ll j = 0; j < n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
ll c2i(pair<ll, ll> c, ll n, ll m)
{
    return c.first * m + c.second;
}
pair<ll, ll> i2c(ll i, ll n, ll m)
{
    return make_pair((i - (i % m)) / m, i % m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, w;
    cin >> n >> m >> w;
    vector<vector<ll>> map(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    vector<vector<pair<ll, ll>>> adj(n * m);
    vector<ll> d;
    vector<ll> p;
    vector<pair<ll, ll>> portals;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (map[i][j] != -1)
            {
                ll idx = c2i({i, j}, n, m);
                if (i + 1 < n)
                {
                    if (map[i + 1][j] != -1)
                    {
                        adj[idx].push_back({c2i({i + 1, j}, n, m), w});
                        adj[c2i({i + 1, j}, n, m)].push_back({idx, w});
                    }
                }
                if (j + 1 < m)
                {
                    if (map[i][j + 1] != -1)
                    {
                        adj[idx].push_back({c2i({i, j + 1}, n, m), w});
                        adj[c2i({i, j + 1}, n, m)].push_back({idx, w});
                    }
                }
                if (map[i][j] != 0)
                {
                    for (auto pr : portals)
                    {
                        adj[idx].push_back({pr.first, pr.second + map[i][j]});
                        adj[pr.first].push_back({idx, pr.second + map[i][j]});
                    }
                    portals.push_back({idx, map[i][j]});
                }
            }
        }
    }
    dijkstra(0, d, p, adj);

    cout << ((d.back()) == INF ? -1 : d.back()) << "\n";
    return 0;
}