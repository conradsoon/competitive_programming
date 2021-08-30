//Credit goes to Steven Halim. This is adapted from his book "Competitive Programming 3".
#include <bits/stdc++.h>
using namespace std;

//getMax Segment Tree that Stores Value, not Index
typedef vector<int> vi;

class SegmentTree {                              // OOP style
    private:
        vi A;                                          // the underlying array
        int n;                                         // n = (int)A.size()
        vi st;                                         // segment tree array
        vi lazy;                                       // lazy propagation array

        int l(int p){
            return  p<<1;
        }                 // go to left child
        
        int r(int p){
            return (p<<1) + 1;
        }              // go to right child

        int operation(int a, int b){
            if(isnan(a)){
                return b;
            }
            else if(isnan(b)){
                return a;
            }
            return a>=b?a:b;
        }

        int getMax(int p, int L, int R, int i, int j) {
            propagate(p, L, R);
            if(i>j){
                return NAN; //Sentinel to indicate don't give a shit.
            }
            if ((L >= i) && (R <= j)){
                return st[p];
            }
            else{
                int m = (L+R)/2;
                return operation(getMax(l(p), L, m, i, min(m, j)), getMax(r(p), m+1, R, max(i, m+1), j));
            }
        }

        void build(int p, int L, int R) {
            if (L == R){
                st[p] = A[L];
            }
            else {
                int m = (L+R)/2;
                build(l(p), L  , m);
                build(r(p), m+1, R);
                st[p] = operation(st[l(p)], st[r(p)]);
            }
        }

        void propagate(int p, int L, int R) {
            if (lazy[p]!=0) {      // has a lazy flag
                if (L != R){
                    lazy[l(p)] += lazy[p];
                    lazy[r(p)] += lazy[p];  
                }     // propagate downwards
                else{                                       // L == R, a single index
                    A[L] += lazy[p];                          // time to update this
                }
                st[p] += lazy[p];                           // not a leaf
                lazy[p] = 0;

            }
        }

        void update(int p, int L, int R, int i, int j, int val) { // O(log n)
            propagate(p, L, R);                          // lazy propagation
            if (i > j){
                return;
            }

            else if ((L >= i) && (R <= j)) {                  // found the segment
                lazy[p] = val;                             // update this
                propagate(p, L, R);                        // lazy propagation
            }

            else {
                int m = (L+R)/2;
                update(l(p), L, m, i, min(m, j), val);
                update(r(p), m+1, R, max(i, m+1), j, val);
                //propagate(l(p), L, m);
                //propagate(r(p), m+1, R);
                st[p] = operation(st[l(p)], st[r(p)]);
            }
        }

    public:
        SegmentTree(int sz) : n(sz), st((int)2*pow(2,ceil(log2(n)))), lazy((int)2*pow(2,ceil(log2(n))), 0) {}

        SegmentTree(const vi &_A) : SegmentTree((int)_A.size()) {
            A = _A;
            build(1, 0, n-1);
        }

        void update(int i, int j, int val) {
            update(1, 0, n-1, i, j, val);
        }

        int getMax(int i, int j) {
            return getMax(1, 0, n-1, i, j);
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int r;
    vi helpme(101500,0);
    cin >> n >> k;
    SegmentTree pkt(helpme);
    while(cin >> r){
        pkt.update(r,r+999,1);
    }
    int max_reqs = pkt.getMax(0,100999);
    cout << ((max_reqs%k) ? ((max_reqs-max_reqs%k)/k+1) : (max_reqs/k)) << "\n";

    return 0;
}