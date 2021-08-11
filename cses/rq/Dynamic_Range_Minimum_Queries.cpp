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
const ll N = 2e5;
ll n; // array size
ull t[2 * N];

void build()
{ // build the tree
	for (ll i = n - 1; i > 0; --i)
		t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void modify(ll p, ll value)
{ // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = min(t[p], t[p ^ 1]);
}

ll query(ll l, ll r)
{ // sum on interval [l, r)
	ull res = 1e10;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res = min(res, t[l++]);
		if (r & 1)
			res = min(res, t[--r]);
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	cin >> n >> q;
	for (ll i = 0; i < n; ++i)
		cin >> t[n + i];
	build();
	ll type, a, b;
	for (ll i = 0; i < q; i++)
	{
		cin >> type >> a >> b;
		if (type == 1)
		{
			modify(a - 1, b);
		}
		else if (type == 2)
		{
			cout << query(a - 1, b) << "\n";
		}
	}
	return 0;
}