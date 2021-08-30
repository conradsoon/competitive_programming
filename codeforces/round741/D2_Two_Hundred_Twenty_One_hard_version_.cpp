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
int sign_sum(vi &pfx, int l, int r)
{
	int sv_sum = pfx[r] - pfx[l - 1];
	sv_sum = (l % 2 ? sv_sum : -sv_sum);
	return sv_sum;
}
int f(vi &pfx, int l, int r, int x)
{
	int sv_sum = sign_sum(pfx, l, r);
	if (x == l && x == r)
	{
		return sign_sum(pfx, x, x);
	}
	else if (x == l)
	{
		return sign_sum(pfx, l + 1, r);
	}
	else if (x == r)
	{
		return sign_sum(pfx, l, r - 1);
	}
	else
	{
		int l_sv_sum = sign_sum(pfx, l, x - 1);
		int r_sv_sum = sign_sum(pfx, x + 1, r);
		return ((x - l) % 2 ? l_sv_sum - r_sv_sum : l_sv_sum + r_sv_sum);
	}
}
int bin_search(vi &pfx, int l, int r, int _l, int _r) //[l,r]
{
	ll m = (_l + _r) / 2;
	ll fl = f(pfx, l, r, _l);
	ll fm = f(pfx, l, r, m);
	ll fr = f(pfx, l, r, _r);
	if (fl == 0)
	{
		return _l;
	}
	if (fm == 0)
	{
		return m;
	}
	if (fr == 0)
	{
		return r;
	}
	if (m == _l)
	{
		return m;
	}
	if (fl * fm < 0)
	{
		return bin_search(pfx, l, r, _l, m);
	}
	else if (fm * fr < 0)
	{
		return bin_search(pfx, l, r, m, _r);
	}
	else
	{
		return -1;
	}
}

void solve()
{
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vi pfx(n + 1);
	pfx[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int mul = (i % 2 ? 1 : -1);
		int num = (s[i - 1] == '+' ? 1 : -1);
		pfx[i] = pfx[i - 1] + mul * num;
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		if ((r - l + 1) % 2)
		{ //odd
			cout << "1\n";
			if (f(pfx, l, r, r) == 0)
			{
				cout << r << "\n";
			}
			else
			{
				cout << bin_search(pfx, l, r, l, r) << "\n";
			}
		}
		else
		{ //even
			int sv_sum = sign_sum(pfx, l, r);
			if (sv_sum == 0)
			{
				cout << "0\n";
			}
			else
			{
				cout << "2\n";
				cout << l << " ";
				if (f(pfx, l, r, r) == 0)
				{
					cout << r << "\n";
				}
				else
				{
					cout << bin_search(pfx, l + 1, r, l + 1, r) << "\n";
				}
			}
		}
	}
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
