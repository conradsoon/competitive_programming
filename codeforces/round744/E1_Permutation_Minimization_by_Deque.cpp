
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
	vi p(n);
	REP(i, 0, n - 1)
	{
		cin >> p[i];
	}
	int m = 1e7;
	deque<int> dq;
	REP(i, 0, n - 1)
	{
		if (p[i] < m)
		{
			dq.push_front(p[i]);
		}
		else
		{
			dq.push_back(p[i]);
		}
		m = min(m, p[i]);
	}
	for (auto x : dq)
	{
		cout << x << " ";
	}
	cout << "\n";
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