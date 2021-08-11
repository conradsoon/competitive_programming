
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vvi pfx(n + 1, vi(n + 1, 0));
	vector<string> inp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> inp[i];
	}
	//build prefix sum
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			pfx[i][j] += pfx[i - 1][j];
			pfx[i][j] += pfx[i][j - 1];
			pfx[i][j] -= pfx[i - 1][j - 1];
			if (inp[i - 1][j - 1] == '*')
			{
				pfx[i][j]++;
			}
		}
	}
	int x1, x2, y1, y2;
	for (int i = 0; i < q; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		cout << pfx[y2][x2] - pfx[y2][x1 - 1] - pfx[y1 - 1][x2] + pfx[y1 - 1][x1 - 1] << "\n";
	}
	return 0;
}