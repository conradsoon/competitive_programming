
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
	vi nums(1050);
	int i = 1;
	for (int k = 1; i <= 1010; k++)
	{
		if (!(k % 3 == 0) && !(k % 10 == 3))
		{
			nums[i] = k;
			i++;
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int q;
		cin >> q;
		cout << nums[q] << "\n";
	}
	return 0;
}