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

ll t[2 * N];

void build()
{ // build the tree
	for (ll i = n - 1; i > 0; --i)
		t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void modify(ll p, ll value)
{ // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = max(t[p], t[p ^ 1]);
}

ll query(ll l, ll r)
{ // sum on interval [l, r)
	ll res = -1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res = max(res, t[l++]);
		if (r & 1)
			res = max(res, t[--r]);
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> t[n + i];
	}
	build();
	for (ll i = 0; i < m; i++)
	{
		int req;
		cin >> req;
		int l = 0;
		int r = n;
		int mid;
		int l_max;
		int r_max;
		bool found = false;
		while (true)
		{
			int mid = l + (r - l) / 2;
			if (mid == l)
			{
				if (t[n + l] >= req)
				{
					found = true;
				}
				break;
			}
			l_max = query(l, mid);
			r_max = query(mid, r);
			if (l_max >= req)
			{
				r = mid;
			}
			else if (r_max >= req)
			{
				l = mid;
			}
			else
			{
				break;
			}
		}
		if (found)
		{
			modify(l, t[l + n] - req);
			cout << l + 1 << " ";
		}
		else
		{
			cout << "0 ";
		}
	}
	return 0;
}