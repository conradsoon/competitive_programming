
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
	int n, l, r;
	cin >> n >> l >> r;
	vi a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		auto litr = lower_bound(a.begin() + i + 1, a.end(), l - a[i]);
		auto ritr = upper_bound(a.begin() + i + 1, a.end(), r - a[i]);
		count += ritr - litr;
	}
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