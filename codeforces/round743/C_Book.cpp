
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
const int INF = 1e8;
void solve()
{
	int n;
	cin >> n;
	vvi reqfor(n);
	vvi uses(n);
	vi min_read(n, INF);
	vector<bool> read(n, false);
	vi c(n, 0);
	priority_queue<int, vector<int>, greater<int>> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	REP(i, 0, n - 1)
	{
		int k;
		cin >> k;
		if (k == 0)
		{
			pq1.push(i);
		}
		REP(j, 0, k - 1)
		{
			int temp;
			cin >> temp;
			temp--;
			reqfor[temp].push_back(i);
			uses[i].push_back(temp);
		}
	}
	int count = 0;
	while (true)
	{
		count++;
		while (!pq1.empty())
		{
			int i = pq1.top();
			pq1.pop();
			if (!read[i])
			{
				if (c[i] == uses[i].size())
				{
					read[i] = true;
					for (auto e : reqfor[i])
					{
						c[e]++;
						if (e > i)
						{
							pq1.push(e);
						}
						else
						{
							pq2.push(e);
						}
					}
				}
			}
		}
		pq1.swap(pq2);
		if (pq1.empty())
		{
			break;
		}
	}
	bool can = true;
	REP(i, 0, n - 1)
	{
		if (!read[i])
		{
			can = false;
			break;
		}
	}
	if (can)
	{
		cout << count << "\n";
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