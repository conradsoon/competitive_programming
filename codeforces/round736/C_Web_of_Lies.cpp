
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
bool isSafe(int i, vector<set<int>> &adj)
{
	if (adj[i].size() == 0)
	{
		return true;
	}
	else
	{
		if ((*adj[i].rbegin()) <= i)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<set<int>> adj(n + 1);
	REP(i, 0, m - 1)
	{
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	int q;
	cin >> q;
	set<int> safe;
	//chk vuln
	REP(i, 1, n)
	{
		if (isSafe(i, adj))
		{
			safe.insert(i);
		}
	}
	REP(r, 0, q - 1)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int a, b;
			cin >> a >> b;
			adj[a].insert(b);
			adj[b].insert(a);
			if (isSafe(a, adj))
			{
				safe.insert(a);
			}
			else
			{
				safe.erase(a);
			}
			if (isSafe(b, adj))
			{
				safe.insert(b);
			}
			else
			{
				safe.erase(b);
			}
		}
		else if (t == 2)
		{
			int a, b;
			cin >> a >> b;
			adj[a].erase(b);
			adj[b].erase(a);
			if (isSafe(a, adj))
			{
				safe.insert(a);
			}
			else
			{
				safe.erase(a);
			}
			if (isSafe(b, adj))
			{
				safe.insert(b);
			}
			else
			{
				safe.erase(b);
			}
		}
		else if (t == 3)
		{
			cout << safe.size() << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}