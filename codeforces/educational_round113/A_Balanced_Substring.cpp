
#include <bits/stdc++.h>

using namespace std;

//TYPEDEFS
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

//MACROS
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = b; i >= a; i--)
//template ends
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi pfx_a(n + 1, 0);
	vi pfx_b(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		pfx_a[i] = pfx_a[i - 1];
		pfx_b[i] = pfx_b[i - 1];
		if (s[i - 1] == 'a')
		{
			pfx_a[i]++;
		}
		else if (s[i - 1] == 'b')
		{
			pfx_b[i]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (pfx_a[j + 1] - pfx_a[i] == pfx_b[j + 1] - pfx_b[i])
			{
				cout << i + 1 << " " << j + 1 << "\n";
				return;
			}
		}
	}
	cout << "-1 -1\n";
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