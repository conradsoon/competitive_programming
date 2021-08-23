
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector<string> pwrs;
	ll p = 1;
	while (p < (ll)1e18)
	{
		pwrs.push_back(to_string(p));
		p *= 2;
	}
	while (t--)
	{
		string n;
		cin >> n;
		ll min_val = n.size() + 1;
		for (auto s : pwrs)
		{
			int s_ptr = 0;
			int n_ptr = 0;
			for (int n_ptr = 0; n_ptr < n.size(); n_ptr++)
			{
				if (s[s_ptr] == n[n_ptr])
				{
					s_ptr++;
				}
			}
			min_val = min(min_val, (ll)(n.size() - s_ptr + (s.size() - s_ptr)));
		}
		cout
			<< min_val << "\n";
	}
	return 0;
}