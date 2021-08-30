#include <bits/stdc++.h>
#include <tuple>
using namespace std;

using namespace std;
class UnionFind {
    private: 
        vector<int> p, rank; // remember: vi is vector<int>
    public:
        UnionFind(int N){
            rank.assign(N, 0);
            p.assign(N, 0); 
            for (int i = 0; i < N; i++){
                p[i] = i;
            }
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { // if from different set
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y]){
                    p[y] = x; // rank keeps the tree short
                }
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]){
                        rank[y]++;
                    }
                }
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int x, y, r;
    vector<int> xv;
    vector<int> yv;
    vector<int> rv;
    vector<pair<double,pair<int,int>>> edges;

    double mstd = 0;
    UnionFind kruskal(n);
    int linked = 0;

    while(cin >> x >> y >> r){
        xv.push_back(x);
        yv.push_back(y);
        rv.push_back(r);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double d = sqrt(pow(xv[i] - xv[j], 2) + pow(yv[i] - yv[j], 2)) - rv[i] - rv[j];
            edges.push_back(make_pair(d, make_pair(i,j)));
        }
    }
    
    sort(edges.begin(), edges.end());
    for(auto e : edges){
        if(linked == n-1){
            break;
        }
        else{
            int e1 = e.second.first;
            int e2 = e.second.second;
            if(kruskal.isSameSet(e1,e2)==false){
                linked++;
                mstd+=e.first;
                kruskal.unionSet(e1,e2);
            }
        }
    }
    cout << setprecision(16) << mstd;
    return 0;
}