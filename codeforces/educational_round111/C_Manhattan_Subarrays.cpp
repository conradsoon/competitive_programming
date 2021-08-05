
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
	ll n;
	cin >> n;
	vll a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	map<ll, ll> max_map;
	map<ll, ll> min_map;
	set<ll> seen;
	for (int i = 0; i < n; i++)
	{
		if (seen.find(a[i]) == seen.end())
		{
			min_map[a[i]] = i;
			seen.insert(a[i]);
		}
		max_map[a[i]] = i;
	}
	ll count = 0;
	count += n * (n + 1) / 2;
	for (auto k : seen)
	{
		if (max_map[k] != min_map[k])
		{
			count -= (min_map[k] + 1) * (n - max_map[k]) - 1;
		}
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