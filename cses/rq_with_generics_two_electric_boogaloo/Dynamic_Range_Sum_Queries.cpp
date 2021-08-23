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
using namespace std;

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
			value[l] = value[2 * l] + value[2 * l + 1];
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
	ll sum;
	ll width;

	node operator+(const node &n)
	{
		return {sum + n.sum, width + n.width};
	}
};

struct update
{
	ll value;
	node operator()(const node &n)
	{
		return {n.width * value, n.width};
	}

	update operator+(const update &u)
	{
		return u;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, q;
	cin >> n >> q;

	seg_tree_lazy<node, update> st(n, {0, 0}, {0});
	vector<node> leaves(n, {0, 1});
	st.set_leaves(leaves);

	for (int i = 0; i < n; i++)
	{
		ll temp;
		cin >> temp;
		st.upd(i, i, {temp});
	}
	for (int i = 0; i < q; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			ll k, u;
			cin >> k >> u;
			st.upd(k - 1, k - 1, {u});
		}
		else if (type == 2)
		{
			ll a, b;
			cin >> a >> b;
			cout << st.query(a - 1, b - 1).sum << "\n";
		}
	}
}