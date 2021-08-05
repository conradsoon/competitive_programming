
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
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	ll ans = 0;
	ans += a * n;
	if (b >= 0)
	{
		ans += b * n;
	}
	else
	{
		char prev_char = 'x';
		int zero_grps = 0;
		int one_grps = 0;
		for (auto c : s)
		{
			if (c != prev_char)
			{
				prev_char = c;
				if (c == '0')
				{
					zero_grps++;
				}
				else if (c == '1')
				{
					one_grps++;
				}
			}
		}
		ans += b * (min(zero_grps, one_grps) + 1);
	}
	cout << ans << "\n";
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