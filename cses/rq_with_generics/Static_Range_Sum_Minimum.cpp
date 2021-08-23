
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
struct minMonoid
{
	ll val;
	minMonoid() : val(1e15) //should initialise to unit for monoid, if no convenient unit exists, should modify plus function and add a boolean to indicate isunit.
	{
	}
	//With reference from:
	minMonoid &operator+=(const minMonoid &rhs) // compound assignment (does not need to be a member,
	{											// but often is, to modify the private members)
		/* addition of rhs to *this takes place here */
		val = min(val, rhs.val);
		return *this; // return the result by reference
	}

	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend minMonoid operator+(minMonoid lhs,		 // passing lhs by value helps optimize chained a+b+c
							   const minMonoid &rhs) // otherwise, both parameters may be const references
	{
		lhs += rhs; // reuse compound assignment
		return lhs; // return the result by value (uses move constructor)
	}				//https://en.cppreference.com/w/cpp/language/operators
};

template <class M>
struct segmentTree
{
	int n;
	vector<M> nodes;
	//initializes to blank segment tree
	segmentTree(int n) : n(n)
	{
		nodes.resize(4 * n);
	}
	//pass in array of monoids to initialise
	segmentTree(vector<M> &values)
	{
		n = values.size();
		nodes.resize(4 * n);
		build(values, 1, 0, n - 1);
	}
	//helper function to build
	void build(vector<M> &values, int v, int tl, int tr)
	{
		if (tl == tr)
		{
			nodes[v] = values[tl];
		}
		else
		{
			int tm = (tl) + (tr - tl) / 2; // do this to prevent overflow instead of conventional average.
			build(values, v * 2, tl, tm);
			build(values, v * 2 + 1, tm + 1, tr);
			nodes[v] = nodes[v * 2] + nodes[v * 2 + 1];
		}
	}
	//wrapper around helper function to find partial sum
	M partialSum(int l, int r) //[l,r]
	{
		return partialSum(1, 0, n - 1, l, r);
	}
	M partialSum(int v, int tl, int tr, int l, int r) //[l, r]
	{
		if (l > r)
			return M();
		if (l == tl && r == tr)
		{
			return nodes[v];
		}
		int tm = (tl) + (tr - tl) / 2; // do this to prevent overflow instead of conventional average.
		return partialSum(v * 2, tl, tm, l, min(r, tm)) + partialSum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
	void update(int pos, M new_val)
	{
		update(1, 0, n - 1, pos, new_val);
	}
	void update(int v, int tl, int tr, int pos, M new_val)
	{
		if (tl == tr)
		{
			nodes[v] = new_val;
		}
		else
		{
			int tm = (tl) + (tr - tl) / 2; // do this to prevent overflow instead of conventional average.
			if (pos <= tm)
				update(v * 2, tl, tm, pos, new_val);
			else
				update(v * 2 + 1, tm + 1, tr, pos, new_val);
			nodes[v] = nodes[v * 2] + nodes[v * 2 + 1];
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<minMonoid> x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i].val;
	}
	segmentTree<minMonoid> st(x);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << st.partialSum(a - 1, b - 1).val << "\n";
	}
	return 0;
}