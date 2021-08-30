#include <bits/stdc++.h>
using namespace std;

template <class T>  
class FenwickTree {
    private:
    vector<T> v;
    int n;

    public:
    FenwickTree(int n) { 
        this->n = n;
        v.assign(n + 1, 0);
    }

    T query(int l, int r) {
        return query(r) - (l==1?0:query(l - 1));
    }

    T query(int r) {
        T sum = 0;
        while (r > 0) {
            sum += v[r];
            r -= (r & (-r));
        }
        return sum;
    }

    void update(int i, T k) {
        while (i < n + 1) {
            v[i] += k;
            i += (i & (-i));
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    FenwickTree<int> ft(n);
    for(int i=0;i<k;i++) {
        char op;
        cin >> op;
        if(op == 'F') {
            int bit;
            cin >> bit;
            if(ft.query(bit) - ft.query(bit-1) == 0) {
                ft.update(bit, 1);
            } else {
                ft.update(bit, -1);
            }
        }
        if(op == 'C') {
            int l, r;
            cin >> l >> r;
            cout << ft.query(r) - ft.query(l) << endl;
        }
    }
}