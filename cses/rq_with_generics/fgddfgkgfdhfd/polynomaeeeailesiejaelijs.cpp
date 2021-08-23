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

struct aggrOp
{
	intAddMonoid val;
	int opType; //1 is increase, 2 is set
	bool hasPendingOp;
	aggrOp() : val(), opType(), hasPendingOp(false)
	{
	}
	aggrOp(ll val, int opType) : val(val), opType(opType), hasPendingOp(true)
	{
	}
	void compose(aggrOp parentOp)
	{
		if (hasPendingOp == false)
		{
			//assert(parentOp.hasPendingOp);
			hasPendingOp = true;
			opType = parentOp.opType;
			val.val = parentOp.val.val;
		}
		else
		{
			if (parentOp.opType == 1)
			{
				val.val += parentOp.val.val;
			}
			else if (parentOp.opType == 2)
			{
				opType = 2;
				val.val = parentOp.val.val;
			}
		}
	}
	intAddMonoid applyAggrOp(intAddMonoid nodeVal, int l, int r)
	{
		if (hasPendingOp)
		{
			if (opType == 1)
			{
				nodeVal.val += val.val * (r - l + 1);
			}
			else if (opType == 2)
			{
				nodeVal.val = val.val * (r - l + 1);
			}
		}
		return nodeVal;
	}
};

template <class M, class F>
struct node
{
	M val;
	F lazyOp;
	bool isLeafNode;
	node() : val(), lazyOp(), isLeafNode(false)
	{
	}
	void compose(F parentOp)
	{
		lazyOp.compose(parentOp);
	}
	void applyAggrOp(int l, int r)
	{
		val = lazyOp.applyAggrOp(val, l, r);
		lazyOp = F(); //resets aggrOp to have no op.
	}
};

template <class M, class F>
struct segmentTree
{
	int n;
	vector<node<M, F>> nodes;
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
		nodes[v].l = tl;
		nodes[v].r = tr;
		if (tl == tr)
		{
			nodes[v].val = values[tl];
		}
		else
		{
			int tm = (tl) + (tr - tl) / 2; // do this to prevent overflow instead of conventional average.
			build(values, v * 2, tl, tm);
			build(values, v * 2 + 1, tm + 1, tr);
			nodes[v].val = nodes[v * 2].val + nodes[v * 2 + 1].val;
		}
	}
	void applyAndPushToKids(int v)
	{
		if (nodes[v].l < nodes[v].r && nodes[v].lazyOp.hasPendingOp) //ensures is not a leaf node, and has pending op
		{
			nodes[2 * v].compose(nodes[v].lazyOp);
			nodes[2 * v + 1].compose(nodes[v].lazyOp);
		}
		//compose before apply, becoz apply resets aggrOp
		nodes[v].applyAggrOp();
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
		else
		{
			applyAndPushToKids(v);
			if (l == tl && r == tr)
			{
				return nodes[v].val;
			}
			int tm = (tl) + (tr - tl) / 2; // do this to prevent overflow instead of conventional average.
			return partialSum(v * 2, tl, tm, l, min(r, tm)) + partialSum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		}
	}
	void update(int l, int r, F newOp) //[l,r]
	{
		update(1, 0, n - 1, l, r, newOp);
	}
	void update(int v, int tl, int tr, int l, int r, F newOp) //[l, r]
	{
		if (l <= r)
		{
			applyAndPushToKids(v);
			if (l == tl && r == tr)
			{
				nodes[v].lazyOp = newOp;
				applyAndPushToKids(v);
				return;
			}
			else
			{
				int tm = (tl) + (tr - tl) / 2; // do this to prevent overflow instead of conventional average.
				update(v * 2, tl, tm, l, min(r, tm), newOp);
				update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, newOp);
				applyAndPushToKids(v * 2);
				applyAndPushToKids(v * 2 + 1);
				nodes[v]
					.val = nodes[v * 2].val + nodes[v * 2 + 1].val;
			}
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
	vector<intAddMonoid> x(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		x[i] = intAddMonoid(temp);
	}
	segmentTree<intAddMonoid, aggrOp> st(x);
	for (int i = 0; i < q; i++)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int a, b, x;
			cin >> a >> b >> x;
			st.update(a - 1, b - 1, aggrOp(x, 1));
		}
		else if (q == 2)
		{
			int a, b, x;
			cin >> a >> b >> x;
			st.update(a - 1, b - 1, aggrOp(x, 2));
		}
		else if (q == 3)
		{
			int a, b;
			cin >> a >> b;
			cout << st.partialSum(a - 1, b - 1).val << "\n";
		}
	}
	return 0;
}