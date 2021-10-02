
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
			 tree_order_statistics_node_update>
	indexed_set;
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
	vii x(n);
	REP(i, 0, n - 1)
	{
		cin >> x[i].F;
		x[i].S = i;
	}
	indexed_set os;
	ll count = 0;
	map<int, int> ft;
	REP(i, 0, n - 1)
	{
		int f = os.order_of_key({x[i].F, -1});
		int b = i - f - ft[x[i].F];
		count += min(f, b);
		ft[x[i].F]++;
		os.insert(x[i]);
	}
	cout << count << "\n";
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