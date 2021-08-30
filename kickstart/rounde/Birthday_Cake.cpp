
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
ll cd(ll a, ll b)
{
	return (a + b - 1) / b;
}
void solve(int n)
{
	int r, c, k;
	cin >> r >> c >> k;
	k = min(k, max(r, c));
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	ll cuts = 0;
	ll vl = r2 - r1 + 1;
	ll hl = c2 - c1 + 1;
	ll vc = cd(vl, k);
	ll hc = cd(hl, k);
	//try all 8 ways of entering into cake
	ll min_edge_cuts = 1e17;
	ll temp = 0;
	//hori cuts
	//1
	if (r1 != 1)
	{
		temp += cd(c2, k);
	}
	if (c1 != 1)
	{
		temp += vc;
	}
	if (r2 != r)
	{
		temp += hc;
	}
	if (c2 != c)
	{
		temp += vc;
	}
	min_edge_cuts = min(min_edge_cuts, temp);
	temp = 0;
	//2
	if (r1 != 1)
	{
		temp += cd(c - c1 + 1, k);
	}
	if (c1 != 1)
	{
		temp += vc;
	}
	if (r2 != r)
	{
		temp += hc;
	}
	if (c2 != c)
	{
		temp += vc;
	}
	min_edge_cuts = min(min_edge_cuts, temp);
	temp = 0;
	//3
	if (r1 != 1)
	{
		temp += hc;
	}
	if (c1 != 1)
	{
		temp += vc;
	}
	if (r2 != r)
	{
		temp += cd(c2, k);
	}
	if (c2 != c)
	{
		temp += vc;
	}
	min_edge_cuts = min(min_edge_cuts, temp);
	temp = 0;
	//4
	if (r1 != 1)
	{
		temp += hc;
	}
	if (c1 != 1)
	{
		temp += vc;
	}
	if (r2 != r)
	{
		temp += cd(c - c1 + 1, k);
	}
	if (c2 != c)
	{
		temp += vc;
	}
	min_edge_cuts = min(min_edge_cuts, temp);
	temp = 0;
	//vert cuts
	//5
	if (r1 != 1)
	{
		temp += hc;
	}
	if (c1 != 1)
	{
		temp += cd(r2, k);
	}
	if (r2 != r)
	{
		temp += hc;
	}
	if (c2 != c)
	{
		temp += vc;
	}
	min_edge_cuts = min(min_edge_cuts, temp);
	temp = 0;
	//6
	if (r1 != 1)
	{
		temp += hc;
	}
	if (c1 != 1)
	{
		temp += cd(r - r1 + 1, k);
	}
	if (r2 != r)
	{
		temp += hc;
	}
	if (c2 != c)
	{
		temp += vc;
	}
	min_edge_cuts = min(min_edge_cuts, temp);
	temp = 0;
	//7
	if (r1 != 1)
	{
		temp += hc;
	}
	if (c1 != 1)
	{
		temp += vc;
	}
	if (r2 != r)
	{
		temp += hc;
	}
	if (c2 != c)
	{
		temp += cd(r2, k);
	}
	min_edge_cuts = min(min_edge_cuts, temp);
	temp = 0;
	//8
	if (r1 != 1)
	{
		temp += hc;
	}
	if (c1 != 1)
	{
		temp += vc;
	}
	if (r2 != r)
	{
		temp += hc;
	}
	if (c2 != c)
	{
		temp += cd(r - r1 + 1, k);
	}
	min_edge_cuts = min(min_edge_cuts, temp);
	temp = 0;
	//8
	//remove double-counting if at edges (or just break into separate case);
	//logic might be fucky, worst case just check inside 1,2,5,6
	cuts += min_edge_cuts;
	//divide up center
	ll min_center_cuts = 1e17;
	temp += (hl - 1) * vc; //vertical cuts
	//full units
	temp += (vl / k) * (k - 1) * hl;
	temp += (vl / k) * hc;
	//left over units
	if (vl % k)
	{
		temp += (vl % k - 1) * hl;
	}
	else
	{
		temp -= hc;
	}
	min_center_cuts = min(min_center_cuts, temp);
	cuts += min_center_cuts;
	cout << "Case #" << n << ": " << cuts << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}
	return 0;
}