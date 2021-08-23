
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
ld hn(ll q)
{
	ld ans = 0;
	ld ldq = (ld)q;
	ans += log(ldq);
	ans += 0.57721566490153286060651209008240243104215933593992; //oily macaroni
	ans += (0.5) * pow(ldq, -1);
	ans += (1 / (ld)12) * pow(ldq, -2);
	ans += (1 / (ld)120) * pow(ldq, -4);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector<ld> memo(1e6 + 50);
	memo[1] = 1;
	for (int i = 2; i < memo.size() - 1; i++)
	{
		memo[i] = memo[i - 1] + 1 / (ld)i;
	}
	for (int i = 1; i <= t; i++)
	{
		ull q;
		cin >> q;
		if (q <= 1e6)
		{
			cout << "Case #" << i << ": " << setprecision(16) << memo[q] << "\n";
		}
		else
		{

			cout << "Case #" << i << ": " << setprecision(16) << hn(q) << "\n";
		}
		//approximation of harmonic series
	}
	return 0;
}