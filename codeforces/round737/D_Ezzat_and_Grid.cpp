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
struct segment
{
	ll l;
	ll r;
};

struct node
{
	int max_rows = 0;
	int row = -1;
	friend bool operator<(const node &lhs, const node &rhs)
	{
		return lhs.max_rows < rhs.max_rows;
	}
};
const int N = 6 * 1e5; // limit for array size
vector<node> t(2 * N);
vector<node> d(N);
int n; // array size
int h;
void apply(int p, node value)
{
	t[p] = value;
	if (p < n)
		d[p] = value;
}

void build(int p)
{
	while (p > 1)
		p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]);
}

void push(int p)
{
	for (int s = h; s > 0; --s)
	{
		int i = p >> s;
		if (d[i].row != -1)
		{
			apply(i << 1, d[i]);
			apply(i << 1 | 1, d[i]);
			d[i] = node();
		}
	}
}

void modify(int l, int r, node value)
{
	l += n, r += n;
	int l0 = l, r0 = r;
	push(l0);
	push(r0 - 1);
	for (; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			apply(l++, value);
		if (r & 1)
			apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

node query(int l, int r)
{
	l += n, r += n;
	push(l);
	push(r - 1);
	node res;
	for (; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res = max(res, t[l++]);
		if (r & 1)
			res = max(t[--r], res);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n_read, m;
	cin >> n_read >> m;
	vector<vector<segment>> segs(n_read);
	set<ll> coords;
	map<ll, int> comp;
	for (int i = 0; i < m; i++)
	{
		ll temp, l, r;
		cin >> temp >> l >> r;
		temp--;
		l--;
		r--;
		segs[temp].push_back({l, r});
		coords.insert(l);
		coords.insert(r);
	}
	n = coords.size();
	h = sizeof(int) * 8 - __builtin_clz(n);
	//create compression map
	int i = 0;
	for (auto it = coords.begin(); it != coords.end(); it++)
	{
		comp[*it] = i;
		i++;
	}
	vi lst(n_read);
	node best_so_far;
	for (int i = 0; i < n_read; i++)
	{
		node best;
		for (auto s : segs[i])
		{
			node q = query(comp[s.l], comp[s.r] + 1);
			best = max(best, q);
		}
		lst[i] = best.row;
		best.max_rows++;
		best.row = i;
		best_so_far = max(best_so_far, best);
		for (auto s : segs[i])
		{
			modify(comp[s.l], comp[s.r] + 1, best);
		}
	}
	cout << n_read - best_so_far.max_rows << "\n";
	int k = best_so_far.row;
	/**
	for (int i = n_read - 1; i >= 0; i--)
	{
		if (i == k)
		{
			k = lst[k];
		}
		else
		{
			cout << i + 1 << " ";
		}
	}
	**/
	return 0;
}