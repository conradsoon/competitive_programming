
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
	string n;
	cin >> n;
	if (stoll(n) <= 9)
	{
		cout << stoll(n) - 1 << "\n";
		return;
	}
	string e;
	string o;
	for (int i = 0; i < n.size(); i++)
	{
		if (i % 2)
		{
			e.push_back(n[i]);
		}
		else
		{
			o.push_back(n[i]);
		}
	}
	ll e_val = stoll(e);
	ll o_val = stoll(o);
	if (e_val == 0)
	{
		cout << o_val - 1 << "\n";
		return;
	}
	if (o_val == 0)
	{
		cout << e_val - 1 << "\n";
		return;
	}
	else
	{
		cout << (o_val + 1) * (e_val + 1) - 2 << "\n";
		return;
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