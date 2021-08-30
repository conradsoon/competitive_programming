//adapted from https://cp-algorithms.com/data_structures/fenwick.html and competitive programmers handbook
//1-indexed
struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n+1, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for (size_t i = 1; i <= a.size(); i++)
            add(i, a[i]);
    }

    int sum(int k)
    {
        int s = 0;
        while (k >= 1)
        {
            s += bit[k];
            k -= k & -k;
        }
        return s;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int k, int x)
    {
        while (k <= n)
        {
            bit[k] += x;
            k += k & -k;
        }
    }
};