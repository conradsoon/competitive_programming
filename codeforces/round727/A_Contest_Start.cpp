
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
	ull n, x, t;
	cin >> n >> x >> t;
	ull count = 0;
	ull itvl = t / x;
	if (n >= itvl + 1)
	{
		ull i = n - itvl;
		count += i * itvl;
	}
	itvl = min(itvl, n);
	count += (itvl) * (itvl - 1) / 2;
	cout << count << "\n";
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