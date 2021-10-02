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
		return {n.sum + value * n.width, n.width};
	}

	update operator+(const update &u)
	{
		return {u.value + value};
	}
};
struct p
{
	int a;
	int i;
};

void solve()
{
	ll n, m;
	cin >> n >> m;
	seg_tree_lazy<node, update> st(n * m, {0, 0}, {0});
	vector<node> leaves(n * m, {0, 1});
	st.set_leaves(leaves);
	vi a(n * m);
	map<int, int> f;
	for (int i = 0; i < n * m; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	map<int, int> ep;
	ll e = 0;
	for (auto kv : f)
	{
		e += kv.second;
		ep[kv.first] = e - 1;
	}
	map<int, queue<int>> order;
	for (auto kv : f)
	{
		int endp = ep[kv.first];
		int r = (endp + 1) % m;
		ll fr = (kv.second - r) / m;
		int endstart = endp - r;
		ll begin_count = kv.second - fr * m - r;
		ll begin_start = endstart - fr * m;
		for (int j = 0; j < begin_count; j++)
		{
			order[kv.first].push(begin_start - j);
		}
		for (int j = 0; j < fr * m; j++)
		{
			order[kv.first].push(endstart - j);
		}
		for (int j = 0; j < r; j++)
		{
			order[kv.first].push(endp - j);
		}
	}
	ll count = 0;
	for (int i = 0; i < n * m; i++)
	{
		int place = order[a[i]].front();
		order[a[i]].pop();
		count += st.query((place / m) * m, place).sum;
		st.upd(place, place, {1});
	}
	cout << count << "\n";
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