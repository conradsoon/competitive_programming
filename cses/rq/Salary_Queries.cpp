#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>	 // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
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
typedef tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	ordered_set os;
	vector<int> salaries(n);
	for (int i = 0; i < n; i++)
	{
		cin >> salaries[i];
		os.insert({salaries[i], i});
	}
	for (int i = 0; i < q; i++)
	{
		char q_type;
		cin >> q_type;
		if (q_type == '?')
		{
			int a, b;
			cin >> a >> b;
			cout << os.order_of_key({b + 1, 0}) - os.order_of_key({a, 0}) << "\n";
		}
		else if (q_type == '!')
		{
			int k, x;
			cin >> k >> x;
			k--;
			os.erase({salaries[k], k});
			salaries[k] = x;
			os.insert({salaries[k], k});
		}
	}
	return 0;
}