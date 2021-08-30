#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

//template ends

//https://cp-algorithms.com/data_structures/fenwick.html

struct FenwickTree
{
    vector<long> bit; // binary indexed tree
    long n;

    FenwickTree(long n)
    {
        this->n = n;
        bit.assign(n+1, 0);
    }

    FenwickTree(vector<long> a) : FenwickTree(a.size())
    {
        for (size_t i = 1; i <= a.size(); i++)
            add(i, a[i]);
    }

    long sum(long k)
    {
        long s = 0;
        while (k >= 1)
        {
            s += bit[k];
            k -= k & -k;
        }
        return s;
    }

    long sum(long l, long r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(long k, long x)
    {
        while (k <= n)
        {
            bit[k] += x;
            k += k & -k;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long N, Q;
    cin >> N >> Q;
    FenwickTree ft(N);
    long a, b;
    while (Q--)
    {
        char comm;
        cin >> comm;
        if (comm == '+')
        {
            cin >> a >> b;
            ft.add(a+1, b);
        }
        else if (comm == '?')
        {
            cin >> a;
            cout << ft.sum(a) << "\n";
        }
    }
    return 0;
}