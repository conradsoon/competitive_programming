
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
struct cave
{
	ll min_req;
	ll k;
};
bool operator<(const cave &lhs, const cave &rhs)
{
	return lhs.min_req < rhs.min_req;
}
/**
bool works(vll &temp, ll &max_index, ll &min_req)
{
	bool works = true;
	for (int i = 0; i < max_index; i++)
	{
		if (min_req <= temp[i])
		{
			works = false;
			break;
		}
	}
	return works;
}
**/
void solve()
{
	int n;
	cin >> n;
	vector<cave> c;
	for (int i = 0; i < n; i++)
	{
		ll k;
		cin >> k;
		vll temp(k);
		ll mx = -1e17;
		for (int j = 0; j < k; j++)
		{
			cin >> temp[j];
			mx = max(mx, temp[j] - j + 1);
		}
		c.push_back({mx, k});
	}
	sort(c.begin(), c.end());
	ll curr_min_req = c[0].min_req;
	ll k_so_far = 0;
	for (int i = 0; i < n; i++)
	{
		if (curr_min_req + k_so_far < c[i].min_req)
		{
			curr_min_req = c[i].min_req - k_so_far;
		}
		k_so_far += c[i].k;
	}
	cout << curr_min_req << "\n";
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