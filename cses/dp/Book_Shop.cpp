
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
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	vi h(n + 1);
	vi s(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	vi dp_pages(n + 1, 0);
	vi dp_cost(n + 1, 0);
	int max_pages = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= i; j--)
		{
			if (dp_cost[j - 1] + h[j] <= x)
			{
				if (dp_pages[j - 1] + s[j] > dp_pages[j])
				{
					dp_pages[j] = dp_pages[j - 1] + s[j];
					dp_cost[j] = dp_cost[j - 1] + h[j];
					max_pages = max(max_pages, dp_pages[j]);
				}
			}
		}
	}
	cout << max_pages;
	return 0;
}