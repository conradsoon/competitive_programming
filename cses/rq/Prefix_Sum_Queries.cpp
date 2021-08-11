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
struct node
{
	node(ll sum = 0, ll max_pfx_sum = 0) : sum(sum), max_pfx_sum(max_pfx_sum)
	{
	}
	ll sum;
	ll max_pfx_sum;
	node operator+(const node &rhs)
	{
		return node(sum + rhs.sum, max(max_pfx_sum, sum + rhs.max_pfx_sum));
	}
};

const int N = 2e5; // limit for array size
int n;			   // array size
node t[2 * N];

void build()
{ // build the tree
	for (int i = n - 1; i > 0; --i)
		t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(ll p, ll value)
{ // set value at position p
	for (t[p += n] = node(value, value); p >>= 1;)
	{
		t[p] = t[p << 1] + t[p << 1 | 1];
	}
}

node query(int l, int r)
{ // sum on interval [l, r)
	node resl;
	node resr;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			resl = resl + t[l++];
		if (r & 1)
			resr = t[--r] + resr;
	}
	return resl + resr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> t[n + i].sum;
		t[n + i].max_pfx_sum = t[n + i].sum;
	}
	build();
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			ll k, u;
			cin >> k >> u;
			k--;
			modify(k, u);
		}
		else if (type == 2)
		{
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			node ans = query(a, b + 1);
			cout << ans.max_pfx_sum << "\n";
		}
	}
	return 0;
}