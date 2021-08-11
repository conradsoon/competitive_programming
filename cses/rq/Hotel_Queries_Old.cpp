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
const ll N = 20;
ll n; // array size

struct hotel
{
	ll free = -1;
	int idx = -1;
};

bool operator<(const hotel &lhs, const hotel &rhs)
{
	if (lhs.free == rhs.free)
	{
		return lhs.idx > rhs.idx;
	}
	else
	{
		return lhs.free < rhs.free;
	}
}

hotel t[2 * N];

void build()
{ // build the tree
	for (ll i = n - 1; i > 0; --i)
		t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void modify(ll p, ll value)
{ // set value at position p
	for (t[p += n].free = value; p > 1; p >>= 1)
		t[p >> 1] = max(t[p], t[p ^ 1]);
}

hotel query(ll l, ll r)
{ // sum on interval [l, r)
	hotel res;
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
	ll temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		t[n + i] = {temp, i};
	}
	build();
	for (ll i = 0; i < m; i++)
	{
		int req;
		cin >> req;
		int l = 0;
		int r = n;
		int mid;
		hotel l_max_hotel;
		hotel r_max_hotel;
		bool found = true;
		while (true)
		{
			int mid = l + (r - l) / 2;
			if (mid == l)
			{
				break;
			}
			l_max_hotel = query(l, mid);
			r_max_hotel = query(mid, r);
			if (l_max_hotel.free >= req)
			{
				r = mid;
			}
			else if (r_max_hotel.free >= req)
			{
				l = mid;
			}
			else
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			modify(l_max_hotel)
					cout
				<< t[n + r].idx + 1 << " ";
		}
		else
		{
			cout << "0 ";
		}
	}
	return 0;
}