
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
	vi a(n);
	vi b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	ll more_sum = 0;
	ll less_sum = 0;
	vii more;
	vii less;
	for (int i = 0; i < n; i++)
	{
		int diff = a[i] - b[i];
		if (diff > 0)
		{
			more.push_back({i, abs(diff)});
			more_sum += diff;
		}
		else if (diff < 0)
		{
			less.push_back({i, abs(diff)});
			less_sum += abs(diff);
		}
	}
	if (more_sum == less_sum)
	{
		cout << more_sum << "\n";
		for (int i = 0, j = 0; i < more.size() || j < less.size();)
		{
			more[i].second--;
			less[j].second--;
			cout << more[i].first + 1 << " " << less[j].first + 1 << "\n";
			if (more[i].second == 0)
			{
				i++;
			}
			if (less[j].second == 0)
			{
				j++;
			}
		}
	}
	else
	{
		cout << "-1\n";
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