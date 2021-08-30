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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vi pfx(n + 1);
	pfx[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int mul = (i % 2 ? 1 : -1);
		int num = (s[i - 1] == '+' ? 1 : -1);
		pfx[i] = pfx[i - 1] + mul * num;
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int sv_sum;
		if (l % 2)
		{
			sv_sum = pfx[r] - pfx[l - 1];
		}
		else
		{
			sv_sum = -(pfx[r] - pfx[l - 1]);
		}
		if (sv_sum == 0)
		{
			cout << "0\n";
		}
		else
		{
			cout << ((r - l + 1) % 2 ? 1 : 2) << "\n";
		}
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