#include <iostream>
#include <string>
#include <vector>
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

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
        rank.assign(N, 0);    // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N;          // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }            // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

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
        --numSets;                // a union reduces numSets
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        int f;
        cin >> f;
        unordered_map<string, int> n2i; //name to index
        UnionFind sn(100001);           //socialnetwork h//100001 upper bound on number of people that can exist in qtn
        while (f--)
        {
            string person_a, person_b;
            cin >> person_a >> person_b;
            if (n2i.find(person_a) == n2i.end())
            {
                n2i[person_a] = n2i.size();
            }
            if (n2i.find(person_b) == n2i.end())
            {
                n2i[person_b] = n2i.size();
            }
            sn.unionSet(n2i[person_a], n2i[person_b]);
            cout << sn.sizeOfSet(n2i[person_a]) << "\n";
        }
    }
    return 0;
}