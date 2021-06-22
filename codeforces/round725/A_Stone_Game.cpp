
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
const int INF = 1e9;
void solve()
{
	int n;
	cin >> n;
	vi a(n);
	for (auto &p : a)
	{
		cin >> p;
	}
	auto mn = min_element(a.begin(), a.end());
	auto mx = max_element(a.begin(), a.end());
	int pos1 = mn - a.begin();
	int pos2 = mx - a.begin();
	if (pos1 > pos2)
	{
		swap(pos1, pos2);
	}
	int k = INF;
	k = min(k, pos2 + 1);
	k = min(k, n - pos1);
	k = min(k, pos1 + 1 + (n - pos2));
	cout << k << "\n";
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