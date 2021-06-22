
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
const ll INF = 1e12;
using namespace std;
void solve()
{
	ll x, y, a, b;
	cin >> x >> y >> a >> b;
	if (x > y)
	{
		swap(x, y);
	}
	if (a > b)
	{
		swap(a, b);
	}
	//from here, wlog assume x<=y ,a<=b;
	if (a == b)
	{
		cout << x / a << "\n";
	}
	else
	{
		ll l = 0;
		ll r = ((x + y) / (a + b)) + 1;
		while (r - l > 1)
		{
			ll n = (l + r) / 2;
			ll left = ceill((ld)(x - n * b) / (a - b));
			ll right = floorl((ld)(y - n * a) / (b - a));
			if (max(left, 0LL) <= min(right, n))
			{
				l = n;
			}
			else
			{
				r = n;
			}
		}
		cout << l << "\n";
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