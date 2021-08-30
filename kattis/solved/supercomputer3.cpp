#include <bits/stdc++.h>
using namespace std;
//Credit goes to Steven Halim. This is adapted from his book "Competitive Programming 3".
class FenwickTree {
    private:
        vector<int> ft;

    public: 
        //Initialises n+1 zeroes.
        FenwickTree(int n){
            ft.assign(n + 1, 0);
        }

        int LSOne(int s){
            return (s & (-s));
        }

        int rsq(int b){ // returns RSQ(1, b)
            int sum = 0;
            for (;b ; b-=LSOne(b)){
                sum += ft[b];
            }
            return sum;
        }

        int rsq(int a, int b){ // returns RSQ(a, b)
            return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
        }

        // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
        void adjust(int k, int v){ // note: n = ft.size() - 1
            for (; k<(int)ft.size(); k += LSOne(k)){
                ft[k] += v;
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, a, b;
    char q;
    cin >> n >> k;
    unordered_set<int> truebits;
    FenwickTree ftree(n);
    while(k--){
        cin >> q;
        if(q=='F'){
            cin >> a;
            if(truebits.count(a)){
                ftree.adjust(a,-1);
                truebits.erase(a);
            }
            else{
                ftree.adjust(a,1);
                truebits.insert(a);
            }
        }
        else if(q=='C'){
            cin >> a >> b;
            cout << ftree.rsq(a,b) << "\n";
        }
    }
    return 0;
}