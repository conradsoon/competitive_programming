
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
	int n, k;
	cin >> n >> k;
	vii a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int blocks = 1;
	int prev = a[0].second;
	for (int i = 1; i < n; i++)
	{
		if (a[i].second != prev + 1)
		{
			blocks++;
		}
		prev = a[i].second;
	}
	if (blocks <= k)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
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