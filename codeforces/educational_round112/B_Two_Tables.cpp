
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
	ll w, h;
	cin >> w >> h;
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll tw, th;
	cin >> tw >> th;
	bool p = false;
	ll m = 1e17;
	if (x2 + tw - x1 <= w)
	{
		m = min(m, tw - x1);
		p = true;
	}
	if (y2 + th - y1 <= h)
	{
		m = min(m, th - y1);
		p = true;
	}
	if (x1 - (x2 - (w - tw)) >= 0)
	{
		m = min(m, x2 - (w - tw));
		p = true;
	}
	if (y1 - (y2 - (h - th)) >= 0)
	{
		m = min(m, y2 - (h - th));
		p = true;
	}
	m = max(m, 0LL);

	if (p)
	{
		cout << m << "\n";
	}
	else
	{
		cout << "-1\n";
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