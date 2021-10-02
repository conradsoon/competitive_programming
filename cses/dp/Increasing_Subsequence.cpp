
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
const ll INF = 1e17;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vll x(n);
	vll dp(n + 10, INF);
	dp[0] = -INF;
	REP(i, 0, n - 1)
	{
		cin >> x[i];
	}
	REP(i, 0, n - 1)
	{
		auto itr = lower_bound(dp.begin(), dp.end(), x[i]);
		*itr = x[i];
	}
	cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() - 1;

	return 0;
}