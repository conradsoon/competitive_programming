#include <bits/stdc++.h>
using namespace std;
struct intAddMonoid
{
	ll val;
	intAddMonoid() : val(0) //should initialise to unit for monoid, if no convenient unit exists, should modify plus function and add a boolean to indicate isunit.
	{
	}
	intAddMonoid(ll x) : val(x)
	{
	}
	//With reference from:
	//https://en.cppreference.com/w/cpp/language/operators
	intAddMonoid &operator+=(const intAddMonoid &rhs) // compound assignment (does not need to be a member,
	{												  // but often is, to modify the private members)
		/* addition of rhs to *this takes place here */
		val += rhs.val;
		return *this; // return the result by reference
	}

	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend intAddMonoid operator+(intAddMonoid lhs,		   // passing lhs by value helps optimize chained a+b+c
								  const intAddMonoid &rhs) // otherwise, both parameters may be const references
	{
		lhs += rhs; // reuse compound assignment
		return lhs; // return the result by value (uses move constructor)
	}
};

template <class M>
struct segmentTree
{
	int n;
	vector<M> nodes;
	//initializes to blank segment tree
	segmentTree(int n) : n(n)
	{
		nodes.resize(4 * n + 1);
	}
	//pass in array of monoids to initialise
	segmentTree(vector<M> &values)
	{
		new (this) segmentTree(values.size());
		n = values.size();
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
			return M(); //should return the identity.
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