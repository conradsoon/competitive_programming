
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
ull MOD = 10e9 + 7;
ld phi = 1.61803398874989484820458683436563811772030917980576286213544862270526046281890;
void solve()
{
	ull n;
	cin >> n;
	cout << n + (ull)floorl(n * phi) << "\n";
	ull ans = (ull)floorl(n * phi * phi) % MOD;
	//cout << ans << "\n";
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