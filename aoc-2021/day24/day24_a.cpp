#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<char>; // char faster
using vvb = vector<vector<char>>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void try_num(string n)
{
	freopen("input.txt", "r", stdin);
	string instr;
	string v1;
	string v2;
	map<string, int> reg;
	reg["x"] = 0;
	reg["y"] = 0;
	reg["z"] = 0;
	reg["w"] = 0;
	int idx = 0;
	string ans;
	while (cin >> instr)
	{
		v1 = "";
		v2 = "";
		if (instr == "inp")
		{
			cin >> v1;
			reg[v1] = n[idx] - '0';
		}
		else if (instr == "add")
		{
			cin >> v1 >> v2;
			if (v2 == "x" || v2 == "y" || v2 == "z" || v2 == "w")
			{
				reg[v1] += reg[v2];
			}
			else
			{
				reg[v1] += stoi(v2, nullptr, 10);
			}
		}
		else if (instr == "mul")
		{
			cin >> v1 >> v2;
			if (v2 == "x" || v2 == "y" || v2 == "z" || v2 == "w")
			{
				reg[v1] *= reg[v2];
			}
			else
			{
				reg[v1] *= stoi(v2, nullptr, 10);
			}
		}
		else if (instr == "div")
		{
			cin >> v1 >> v2;
			if (v2 == "x" || v2 == "y" || v2 == "z" || v2 == "w")
			{
				reg[v1] /= reg[v2];
			}
			else
			{
				reg[v1] /= stoi(v2, nullptr, 10);
			}
		}
		else if (instr == "mod")
		{
			cin >> v1 >> v2;
			if (v2 == "x" || v2 == "y" || v2 == "z" || v2 == "w")
			{
				reg[v1] %= reg[v2];
			}
			else
			{
				reg[v1] %= stoi(v2, nullptr, 10);
			}
		}
		else if (instr == "eql")
		{
			cin >> v1 >> v2;
			if (v2 == "x" || v2 == "y" || v2 == "z" || v2 == "w")
			{
				reg[v1] = reg[v1] == reg[v2];
			}
			else
			{
				reg[v1] = reg[v1] == stoi(v2, nullptr, 10);
			}
		}
		cout << instr << " ";
		cout << v1 << " ";
		cout << v2 << " ";
		cout << endl;
		cout << reg["x"] << " ";
		cout << reg["y"] << " ";
		cout << reg["z"] << " ";
		cout << reg["w"] << " ";
		cout << endl;
	}
	bool flag = false;
	if (reg["z"] == 0)
	{
		cout << n << endl;
	}
}
int main()
{
	try_num("12345678912345");
	return 1;
}
