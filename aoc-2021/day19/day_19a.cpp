#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<char>; // char faster
using vvb = vector<vector<char>>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct p
{
	int x;
	int y;
	int z;
};

bool operator==(const p &p1, const p &p2)
{
	return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;
}
bool operator<(const p &p1, const p &p2)
{
	if (p1.x == p2.x)
	{
		if (p1.y == p2.y)
		{
			return p1.z < p2.z;
		}
		return p1.y < p2.y;
	}
	return p1.x < p2.x;
}
p dv(const p &l, const p &r)
{
	return {r.x - l.x, r.y - l.y, r.z - l.z};
}

p add(const p &p1, const p &p2)
{
	return {p1.x + p2.x, p1.y + p2.y, p1.z + p2.z};
}

struct corr
{
	int r = 0;
	p del = {0, 0, 0};
	int par = -1;
};

ll sqd(p &p1, p &p2)
{
	ll ans = 0;
	ans += (p1.x - p2.x) * (p1.x - p2.x);
	ans += (p1.y - p2.y) * (p1.y - p2.y);
	ans += (p1.z - p2.z) * (p1.z - p2.z);
	return ans;
}

int cbds(vl &b1d, vl &b2d) // count beacon distance same
{
	map<ll, int> f;
	for (auto d : b1d)
	{
		f[d]++;
	}
	for (auto d : b2d)
	{
		f[d]++;
	}
	int c = 0;
	for (auto kv : f)
	{
		if (kv.se >= 2)
		{
			c++;
		}
	}
	return c;
}

vii matches(vvl &d1, vvl &d2)
{
	int n1 = sz(d1);
	int n2 = sz(d2);
	vb u1(n1, false);
	vb u2(n2, false);
	vii mtch;
	forn(i, 0, n1)
	{
		if (u1[i])
		{
			continue;
		}
		forn(j, 0, n2)
		{
			if (u2[i])
			{
				continue;
			}
			int sdn = cbds(d1[i], d2[j]);
			if (sdn >= 12)
			{
				mtch.pb({i, j});
				u1[i] = true;
				u2[i] = true;
			}
		}
	}
	return mtch;
}

p rot(p &pos, int r)
{
	p a = {0, 0, 0};
	switch (r)
	{
	case 0:
		a.x = pos.x;
		a.y = pos.y;
		a.z = pos.z;
		break;

	case 1:
		a.x = pos.x;
		a.y = pos.z;
		a.z = pos.y;
		break;

	case 2:
		a.x = pos.y;
		a.y = pos.x;
		a.z = pos.z;
		break;

	case 3:
		a.x = pos.y;
		a.y = pos.z;
		a.z = pos.x;
		break;

	case 4:
		a.x = pos.z;
		a.y = pos.x;
		a.z = pos.y;
		break;

	case 5:
		a.x = pos.z;
		a.y = pos.y;
		a.z = pos.x;
		break;

	case 6:
		a.x = pos.x;
		a.y = pos.y;
		a.z = -pos.z;
		break;

	case 7:
		a.x = pos.x;
		a.y = pos.z;
		a.z = -pos.y;
		break;

	case 8:
		a.x = pos.y;
		a.y = pos.x;
		a.z = -pos.z;
		break;

	case 9:
		a.x = pos.y;
		a.y = pos.z;
		a.z = -pos.x;
		break;

	case 10:
		a.x = pos.z;
		a.y = pos.x;
		a.z = -pos.y;
		break;

	case 11:
		a.x = pos.z;
		a.y = pos.y;
		a.z = -pos.x;
		break;

	case 12:
		a.x = pos.x;
		a.y = -pos.y;
		a.z = pos.z;
		break;

	case 13:
		a.x = pos.x;
		a.y = -pos.z;
		a.z = pos.y;
		break;

	case 14:
		a.x = pos.y;
		a.y = -pos.x;
		a.z = pos.z;
		break;

	case 15:
		a.x = pos.y;
		a.y = -pos.z;
		a.z = pos.x;
		break;

	case 16:
		a.x = pos.z;
		a.y = -pos.x;
		a.z = pos.y;
		break;

	case 17:
		a.x = pos.z;
		a.y = -pos.y;
		a.z = pos.x;
		break;

	case 18:
		a.x = pos.x;
		a.y = -pos.y;
		a.z = -pos.z;
		break;

	case 19:
		a.x = pos.x;
		a.y = -pos.z;
		a.z = -pos.y;
		break;

	case 20:
		a.x = pos.y;
		a.y = -pos.x;
		a.z = -pos.z;
		break;

	case 21:
		a.x = pos.y;
		a.y = -pos.z;
		a.z = -pos.x;
		break;

	case 22:
		a.x = pos.z;
		a.y = -pos.x;
		a.z = -pos.y;
		break;

	case 23:
		a.x = pos.z;
		a.y = -pos.y;
		a.z = -pos.x;
		break;

	case 24:
		a.x = -pos.x;
		a.y = pos.y;
		a.z = pos.z;
		break;

	case 25:
		a.x = -pos.x;
		a.y = pos.z;
		a.z = pos.y;
		break;

	case 26:
		a.x = -pos.y;
		a.y = pos.x;
		a.z = pos.z;
		break;

	case 27:
		a.x = -pos.y;
		a.y = pos.z;
		a.z = pos.x;
		break;

	case 28:
		a.x = -pos.z;
		a.y = pos.x;
		a.z = pos.y;
		break;

	case 29:
		a.x = -pos.z;
		a.y = pos.y;
		a.z = pos.x;
		break;

	case 30:
		a.x = -pos.x;
		a.y = pos.y;
		a.z = -pos.z;
		break;

	case 31:
		a.x = -pos.x;
		a.y = pos.z;
		a.z = -pos.y;
		break;

	case 32:
		a.x = -pos.y;
		a.y = pos.x;
		a.z = -pos.z;
		break;

	case 33:
		a.x = -pos.y;
		a.y = pos.z;
		a.z = -pos.x;
		break;

	case 34:
		a.x = -pos.z;
		a.y = pos.x;
		a.z = -pos.y;
		break;

	case 35:
		a.x = -pos.z;
		a.y = pos.y;
		a.z = -pos.x;
		break;

	case 36:
		a.x = -pos.x;
		a.y = -pos.y;
		a.z = pos.z;
		break;

	case 37:
		a.x = -pos.x;
		a.y = -pos.z;
		a.z = pos.y;
		break;

	case 38:
		a.x = -pos.y;
		a.y = -pos.x;
		a.z = pos.z;
		break;

	case 39:
		a.x = -pos.y;
		a.y = -pos.z;
		a.z = pos.x;
		break;

	case 40:
		a.x = -pos.z;
		a.y = -pos.x;
		a.z = pos.y;
		break;

	case 41:
		a.x = -pos.z;
		a.y = -pos.y;
		a.z = pos.x;
		break;

	case 42:
		a.x = -pos.x;
		a.y = -pos.y;
		a.z = -pos.z;
		break;

	case 43:
		a.x = -pos.x;
		a.y = -pos.z;
		a.z = -pos.y;
		break;

	case 44:
		a.x = -pos.y;
		a.y = -pos.x;
		a.z = -pos.z;
		break;

	case 45:
		a.x = -pos.y;
		a.y = -pos.z;
		a.z = -pos.x;
		break;

	case 46:
		a.x = -pos.z;
		a.y = -pos.x;
		a.z = -pos.y;
		break;

	case 47:
		a.x = -pos.z;
		a.y = -pos.y;
		a.z = -pos.x;
		break;
	}
	return a;
}

int rn = 48;
int main()
{
	freopen("input.txt", "r", stdin);
	int nb;
	cin >> nb;
	vector<vector<p>> s(nb);
	vector<vector<vector<ll>>> d(nb);
	vector<corr> corrns(nb);
	forn(i, 0, nb)
	{
		int idx, np;
		cin >> idx >> np;
		s[idx].resize(np);
		forn(j, 0, np)
		{
			p temp;
			cin >> temp.x >> temp.y >> temp.z;
			s[idx][j] = temp;
		}
		d[idx].resize(np, vl(np));
		forn(j, 0, np)
		{
			forn(k, j, np)
			{
				d[idx][j][k] = sqd(s[idx][j], s[idx][k]);
				d[idx][k][j] = d[idx][j][k];
			}
		}
	}
	vb ub(nb, false);
	queue<int> t2m;
	t2m.push(0);
	ub[0] = true;
	while (!t2m.empty())
	{
		int par = t2m.front();
		t2m.pop();
		forn(chld, 0, nb)
		{
			if (ub[chld])
			{
				continue;
			}
			vii mn = matches(d[par], d[chld]);
			if (sz(mn) >= 12)
			{
				ub[chld] = true;
				t2m.push(chld);
				// find rotation
				vi posrots;
				p d1p = dv(s[par][mn[0].fi], s[par][mn[1].fi]);
				p d2p = dv(s[par][mn[0].fi], s[par][mn[2].fi]);
				p d3p = dv(s[par][mn[0].fi], s[par][mn[3].fi]);
				p d1c = dv(s[chld][mn[0].se], s[chld][mn[1].se]);
				p d2c = dv(s[chld][mn[0].se], s[chld][mn[2].se]);
				p d3c = dv(s[chld][mn[0].se], s[chld][mn[3].se]);
				forn(r, 0, rn)
				{
					if (d1p == rot(d1c, r) && d2p == rot(d2c, r) && d2p == rot(d2c, r))
					{
						posrots.pb(r);
					}
				}
				// add check for ambiguous rotation.
				assert(sz(posrots) == 1);
				// find delta
				int r = posrots[0];
				corrns[chld].r = r;
				corrns[chld].par = par;
				corrns[chld].del = add(dv(s[par][mn[0].fi], {0, 0, 0}), dv({0, 0, 0}, rot(s[chld][mn[0].se], r)));
			}
		}
	}
	forn(i, 0, nb)
	{
		int idx = i;

		while (idx != 0)
		{
			forn(j, 0, sz(s[i]))
			{
				s[i][j] = rot(s[i][j], corrns[idx].r);
				s[i][j] = add(s[i][j], dv(corrns[idx].del, {0, 0, 0}));
			}
			idx = corrns[idx].par;
		}
	}
	set<p> pts;
	forn(i, 0, nb)
	{
		forn(j, 0, sz(s[i]))
		{
			pts.insert(s[i][j]);
		}
	}
	cout << sz(pts) << endl;
	return 1;
}
