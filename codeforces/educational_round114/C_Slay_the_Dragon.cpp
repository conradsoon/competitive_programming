
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

ll f(ll x, ll y, ll sum, ll a)
{
	return max(0LL, x - a) + max(0LL, y - (sum - a));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vll a(n);
	ll sum = 0;
	REP(i, 0, n - 1)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	int m;
	cin >> m;
	vll x(m);
	vll y(m);
	REP(i, 0, m - 1)
	{
		cin >> x[i];
		cin >> y[i];
	}
	//attack
	REP(i, 0, m - 1)
	{
		/**
		vll fv(n);
		REP(j, 0, n - 1)
		{
			fv[j] = f(x[i], y[i], sum, a[j]);
		}
		**/
		auto lb = lower_bound(a.begin(), a.end(), x[i]);
		ll ans1 = f(x[i], y[i], sum, *lb);
		ll ans2 = f(x[i], y[i], sum, *(lb - 1));
		cout << min(ans1, ans2) << "\n";
	}
	return 0;
}