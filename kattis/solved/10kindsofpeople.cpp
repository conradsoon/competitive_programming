#include <bits/stdc++.h>
using namespace std;
class UnionFind {
    private: 
        vector<int> p, rank; // remember: vi is vector<int>
    public:
        vector<int> map; // remember: vi is vector<int>
        UnionFind(int N){
            map.assign(N, 0);
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
    int w, h, c, k;
    int x_1, y_1, x_2, y_2;
    int p_1, p_2;
    scanf("%d %d", &h, &w);
    UnionFind state=UnionFind(w*h);
    for(int i=0; i<w*h; i++){
        scanf("%1u", &c);
        state.map[i] = c;
        //CHECKLEFT
        if(i%w != 0){
            if(state.map[i] == state.map[i-1]){
                state.unionSet(i, i-1);
            }
        }
        //CHECKUP
        if(i >= w){
            if(state.map[i] == state.map[i-w]){
                state.unionSet(i, i-w);
            }
        }
    }
    scanf("%d", &k);
    for(int j=0; j<k; j++){
        scanf("%d%d%d%d", &y_1, &x_1, &y_2, &x_2);
        p_1 = (x_1 - 1) + (y_1 - 1)*w;
        p_2 = (x_2 - 1) + (y_2 - 1)*w;
        if(state.isSameSet(p_1, p_2)){
            printf(state.map[p_1]==1?"decimal\n":"binary\n");
        }
        else{
            printf("neither\n");
        }
    }
}