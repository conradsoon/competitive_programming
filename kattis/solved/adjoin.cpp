#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
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

//template ends

class UnionFind
{ // OOP style
private:
    vi p, rank, setSize; // vi p is the key part
    int numSets;
    unordered_set<int> disjointSets;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
        {
            p[i] = i;
            disjointSets.insert(i);
        }
        rank.assign(N, 0);    // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N;          // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }            // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
    unordered_set<int> findDisjointSets()
    {
        return disjointSets;
    }
    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;                         // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y])
            swap(x, y); // keep x 'shorter' than y
        p[x] = y;       // set x under y
        if (rank[x] == rank[y])
            ++rank[y];            // optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        disjointSets.erase(x);
        --numSets; // a union reduces numSets
    }
};
vvi adj;

pair<int, int> find_furthest(int n)
{
    queue<int> q;
    //use an unordered_map instead of a vector for O(1) access because vectors of large sizes have a lot slower access times bcoz not in cpu cache
    //see https://softwareengineering.stackexchange.com/questions/360417/why-is-accessing-elements-of-a-huge-dynamically-allocated-structure-a-lot-slower for details
    unordered_map<int,int> depth;
    depth[n] = 0;
    q.push(n);
    while (true)
    {
        int parent = q.front();
        for (auto child : adj[parent])
        {
            if (depth.find(child) == depth.end())
            {
                depth[child] = depth[parent] + 1;
                q.push(child);
            }
        }
        if (q.size() == 1)
        {
            break;
        }
        q.pop();
    }
    return {q.front(), depth[q.front()]};
}

int find_diameter(int i)
{
    //https://cs.stackexchange.com/questions/22855/algorithm-to-find-diameter-of-a-tree-using-bfs-dfs-why-does-it-work
    pair<int, int> u = find_furthest(i);
    pair<int, int> v = find_furthest(u.first);
    return v.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c, l;
    cin >> c >> l;
    UnionFind g(c);
    adj.resize(c, vi());
    while (l--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        g.unionSet(a, b);
    }
    unordered_set<int> disjointTrees = g.findDisjointSets();
    vector<int> diameters;
    for (auto i : disjointTrees)
    {
        diameters.push_back(find_diameter(i));
    }
    sort(diameters.begin(), diameters.end());
    while (diameters.size() > 1)
    {
        int d1, d2;
        d1 = diameters.back();
        diameters.pop_back();
        d2 = diameters.back();
        diameters.pop_back();
        int d3 = (((d1%2)+d1)/2) + (((d2%2)+d2)/2) + 1;
        diameters.push_back(max({d1,d2,d3}));
    }
    cout << diameters.back();

    return 0;
}