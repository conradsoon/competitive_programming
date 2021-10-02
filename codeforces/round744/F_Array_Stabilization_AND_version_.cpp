
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
int longest_cycle(vi &cycle)
{
	int mx = 0;
	int curr_cycle = 0;
	bool flag = false;
	//check if all ones
	REP(i, 0, (int)cycle.size() - 1)
	{
		if (cycle[i] == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		REP(i, 0, (int)cycle.size() * 2 + 5)
		{
			if (cycle[i % cycle.size()])
			{
				curr_cycle++;
				mx = max(mx, curr_cycle);
			}
			else
			{
				curr_cycle = 0;
			}
		}
		return mx;
	}
	else
	{
		return -1;
	}
}

void solve(int tc)
{
	int n, d;
	cin >> n >> d;
	vi x(n);
	REP(i, 0, n - 1)
	{
		cin >> x[i];
	}
	vvi cycles(n / (n / __gcd(n, d)));
	REP(i, 0, (int)cycles.size() - 1)
	{
		int j = i;
		int s = i;
		while (true)
		{
			cycles[i].push_back(x[j]);
			j += d;
			j %= n;
			if (s == j)
			{
				break;
			}
		}
	}
	int mx = -1;
	bool flag = false;
	REP(i, 0, (int)cycles.size() - 1)
	{
		int cycle_length = longest_cycle(cycles[i]);
		if (cycle_length == -1)
		{
			flag = true;
			break;
		}
		mx = max(cycle_length, mx);
	}
	if (flag)
	{
		cout << "-1\n";
	}
	else
	{
		cout << mx << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	REP(i, 1, t)
	{
		solve(i);
	}
	return 0;
}