#include <bits/stdc++.h>
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
    int n, m;
    int a,b;
    cin >> n >> m;
    UnionFind state(n+1);
    while(m--){
        cin >> a >> b;
        state.unionSet(a,b);
    }
    vector<int> notConnected;
    for(int i=1; i<=n; i++){
        if(state.isSameSet(1,i)==false){
            notConnected.push_back(i);
        }
    }
    if(notConnected.size()>0){
        for(auto const nc : notConnected){
            cout << nc << "\n";
        }
    }
    else{
        cout << "Connected";
    }
    return 0;
}