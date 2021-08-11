
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

const ll N = 8; // limit for array size
ll n;			// array size
ll t[2 * N];
ll h = sizeof(ll) * 8 - __builtin_clz(n);
ll d[N];

void apply(ll p, ll value)
{
	t[p] += value;
	if (p < n)
		d[p] += value;
}

void build(ll p)
{
	while (p > 1)
		p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
}

void push(ll p)
{
	for (ll s = h; s > 0; --s)
	{
		ll i = p >> s;
		if (d[i] != 0)
		{
			apply(i << 1, d[i]);
			apply(i << 1 | 1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(ll l, ll r, ll value)
{
	l += n, r += n;
	ll l0 = l, r0 = r;
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

ll query(ll l, ll r)
{
	l += n, r += n;
	push(l);
	push(r - 1);
	ll res = -2e17;
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
	int q;
	cin >> n >> q;
	vector<ll> x(n);
	vector<ll> pfx(n);
	ll cum_sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		cum_sum += x[i];
		pfx[i] = cum_sum;
		inc(i, n, x[i]);
	}
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			ll k, u;
			cin >> k >> u;
			k--;
			inc(k, n, u - x[k]);
			x[k] = u;
		}
		else if (type == 2)
		{
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			ll ans = query(a, b + 1);
			if (a > 0)
			{
				ans -= pfx[a - 1];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}