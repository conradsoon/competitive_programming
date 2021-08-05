
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
	int n, m;
	cin >> n >> m;
	vector<string> orig(n);
	vector<string> end(n - 1);
	for (int i = 0; i < n; i++)
	{
		cin >> orig[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> end[i];
	}
	string temp3;
	for (int i = 0; i < m; i++)
	{
		ll orig_sum = 0;
		ll end_sum = 0;
		for (int j = 0; j < n; j++)
		{
			orig_sum += orig[j][i] - 'a';
		}
		for (int j = 0; j < n - 1; j++)
		{
			end_sum += end[j][i] - 'a';
		}
		temp3 += (char)('a' + (orig_sum - end_sum));
	}
	cout << temp3 << endl;
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