#include <bits/stdc++.h>
using namespace std;

//TYPEDEFS
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

//MACROS
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = b; i >= a; i--)
//https://codeforces.com/blog/entry/20528
template <typename T, typename U>
struct seg_tree_lazy
{
    int S, H;

    T zero;
    vector<T> value;

    U noop;
    vector<bool> dirty;
    vector<U> prop;

    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U())
    {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S;)
            S *= 2, H++;

        value.resize(2 * S, zero);
        dirty.resize(2 * S, false);
        prop.resize(2 * S, noop);
    }

    void set_update_indices()
    {
        for (int i = 1; i < prop.size(); i++)
        {
            prop[i].s = value[i].s;
            prop[i].e = value[i].e;
        }
    }

    void set_leaves(vector<T> &leaves)
    {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
        set_update_indices();
    }

    void apply(int i, U &update)
    {
        value[i] = update(value[i]);
        if (i < S)
        {
            //prop[i] = prop[i] + update;
            prop[i] = prop[i].combine(update);
            dirty[i] = true;
        }
    }

    void rebuild(int i)
    {
        for (int l = i / 2; l; l /= 2)
        {
            T combined = value[2 * l] + value[2 * l + 1];
            value[l] = prop[l](combined); //define a no-op boolean for funkier shit.
        }
    }

    void propagate(int i)
    {
        for (int h = H; h > 0; h--)
        {
            int l = i >> h;

            if (dirty[l])
            {
                apply(2 * l, prop[l]);
                apply(2 * l + 1, prop[l]);

                prop[l].setNoOp();
                dirty[l] = false;
            }
        }
    }

    void upd(int i, int j, U update)
    {
        i += S, j += S;
        propagate(i), propagate(j);

        for (int l = i, r = j; l <= r; l /= 2, r /= 2)
        {
            if ((l & 1) == 1)
                apply(l++, update);
            if ((r & 1) == 0)
                apply(r--, update);
        }

        rebuild(i), rebuild(j);
    }

    T query(int i, int j)
    {
        i += S, j += S;
        propagate(i), propagate(j);

        T res_left = zero, res_right = zero;
        for (; i <= j; i /= 2, j /= 2)
        {
            if ((i & 1) == 1)
                res_left = res_left + value[i++];
            if ((j & 1) == 0)
                res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct node
{
    ll width;
    ll sum;
    int s;
    int e;
    node operator+(const node &n)
    {
        return {width + n.width, sum + n.sum, s, n.e};
    }
};

struct update
{
    ll a;
    ll d;
    int s;
    int e;
    bool isNoOp;
    node operator()(const node &n)
    {
        node ans = n;
        if (!isNoOp)
        {
            ans.sum += a * n.width;
            ans.sum += (n.width - 1) * (n.width) / 2 * d;
        }
        return ans;
    }

    void setNoOp()
    {
        a = 0;
        d = 0;
        isNoOp = false;
    }

    update combine(const update &pu)
    {
        update ans = *this;
        if (!pu.isNoOp)
        {
            ans.a += a;
            ans.a += (pu.s - s) * d;
            ans.d += pu.d;
            ans.isNoOp = false;
        }
        return ans;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    int n_r = 1;
    while (n_r < n)
    {
        n_r *= 2;
    }
    seg_tree_lazy<node, update> st(n_r, {0, 0, -1, -1}, {0, 0, -1, -1, true});

    vector<node> leaves(n_r, {1, 0, -1, -1});
    for (int i = 0; i < n; i++)
    {
        cin >> leaves[i].sum;
        leaves[i].s = i;
        leaves[i].e = i;
    }
    for (int i = n; i < n_r; i++)
    {
        leaves[i].s = i;
        leaves[i].e = i;
    }
    st.set_leaves(leaves);
    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            st.upd(a - 1, b - 1, {1, 1, a - 1, b - 1, false});
        }
        else if (t == 2)
        {
            cout << st.query(a - 1, b - 1).sum << "\n";
        }
    }
}