
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
//template ends
ll MOD;

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

	void set_leaves(vector<T> &leaves)
	{
		copy(leaves.begin(), leaves.end(), value.begin() + S);

		for (int i = S - 1; i > 0; i--)
			value[i] = value[2 * i] + value[2 * i + 1];
	}

	void apply(int i, U &update)
	{
		value[i] = update(value[i]);
		if (i < S)
		{
			prop[i] = prop[i] + update;
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

				prop[l] = noop;
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
	bool isIdentity;
	bool isWhole;
	ll le;
	ll lw;
	ll re;
	ll rw;
	ll bw;
	node operator+(const node &n)
	{
		if (isIdentity)
		{
			return n;
		}
		else if (n.isIdentity)
		{
			return *this;
		}
		else
		{
			node ans;
			ans.isIdentity = false;
			ans.isWhole = false;
			ans.le = le;
			ans.lw = lw;
			ans.re = n.re;
			ans.rw = n.rw;
			ans.bw = max(bw, n.bw);
			//check if merge
			if (re % MOD == n.le % MOD)
			{
				if (isWhole)
				{
					ans.lw = lw + n.lw;
				}
				if (n.isWhole)
				{
					ans.rw = rw + n.rw;
				}
				ans.bw = max(ans.bw, rw + n.lw);
				ans.isWhole = isWhole && n.isWhole;
			}
			return ans;
		}
	}
};

struct update
{
	node operator()(const node &n)
	{
		return n;
	}

	update operator+(const update &u)
	{
		return u;
	}
};
void solve()
{
	int n;
	cin >> n;
	vector<node> leaves(n);
	seg_tree_lazy<node, update> st(n, {true, false, -1, 0, -1, 0, 0}, {});
	REP(i, 0, n - 1)
	{
		ll temp;
		cin >> temp;
		leaves[i] = {false,
					 true,
					 temp,
					 1,
					 temp,
					 1,
					 1};
	}
	st.set_leaves(leaves);
	cout <<
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}