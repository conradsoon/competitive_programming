
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
void solve()
{
	int n;
	cin >> n;
	vll c(n);
	vll pfx(n);
	pfx[0] = c[0];
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		if (i % 2)
		{
			c[i] = -c[i];
		}
	}
	ull count = 0;
	for (int i = 1; i < n; i++)
	{
		pfx[i] = c[i] + pfx[i - 1];
	}
	for (int i = 0; i < n; i += 2)
	{
		for (int j = n - 1 - (n % 2); j > i; j -= 2)
		{
			ll bal = pfx[j - 1] - pfx[i];
			ll l = c[i];
			ll r = c[j];
			if (bal > 0)
			{
				r += bal;
			}
			if (bal < 0)
			{
				l -= bal;
			}
			count += (ull)max(min(l, abs(r)), (ll)0);
		}
	}
	cout << count;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}