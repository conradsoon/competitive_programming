#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>

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
	vii a(n);
	REP(i, 0, n - 1)
	{
		cin >> a[i].F;
		a[i].S = i + 1;
	}
	ll count = 0;
	set<pii> s(a.begin(), a.end());
	while ((*s.begin()).F == 0 && s.size() >= 1)
	{
		s.erase(s.begin());
	}
	stringstream buff;
	while (true)
	{
		if (s.size() < 2)
		{
			break;
		}
		pii top2 = *s.begin();
		s.erase(s.begin());
		pii top1 = *(--s.end());
		s.erase(--s.end());
		count++;
		top1.F--;
		top2.F--;
		buff << top2.S << " " << top1.S << "\n";
		if (top1.F != 0)
		{
			s.insert(top1);
		}
		if (top2.F != 0)
		{
			s.insert(top2);
		}
	}
	cout << count << "\n";
	cout << buff.str();
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