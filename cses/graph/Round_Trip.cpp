#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<char>; //char faster
using vvb = vector<vector<char>>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, end = (b); i < end; i++)       //[a,b)
#define fornr(i, a, b) for (int i = b - 1, end = (a); i >= end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, end = (b); i <= end; i++)      //[a,b]
#define repnr(i, a, b) for (int i = b, end = (a); i >= end; i--)     //[a,b] reversed
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Graph
{
public:
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;
    vi cycle;
    int cycle_start, cycle_end;
    Graph(int n) : n(n)
    {
        adj.assign(n, vi());
        visited.assign(n, 0);
        parent.assign(n, -1);
    }
    bool dfs(int v, int par)
    { // passing vertex and its parent vertex
        visited[v] = true;
        for (int u : adj[v])
        {
            if (u == par)
                continue; // skipping edge to parent vertex
            if (visited[u])
            {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        }
        return false;
    }
    void add_edge(int a, int b) //a-->b
    {
        adj[a].pb(b);
    }
    void find_cycle()
    {
        visited.assign(n, false);
        parent.assign(n, -1);
        cycle_start = -1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dfs(v, parent[v]))
                break;
        }

        if (cycle_start == -1)
        {
        }
        else
        {
            cycle.push_back(cycle_start);
            for (int v = cycle_end; v != cycle_start; v = parent[v])
                cycle.push_back(v);
            cycle.push_back(cycle_start);
            reverse(cycle.begin(), cycle.end());
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    Graph g(n);
    forn(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    g.find_cycle();
    if (sz(g.cycle))
    {
        cout << sz(g.cycle) << "\n";
        for (auto x : g.cycle)
        {
            cout << x + 1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}