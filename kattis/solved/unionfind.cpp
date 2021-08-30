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
    int n, q;
    char op;
    int a,b;
    cin >> n >> q;
    UnionFind state(n+10);
    while(q--){
        cin >> op >> a >> b;
        if(op=='?'){
            cout << (state.isSameSet(a,b)?"yes\n":"no\n");
        }
        else if(op=='='){
            state.unionSet(a,b);
        }
    }
    return 0;
}