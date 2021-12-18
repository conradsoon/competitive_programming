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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output_a.txt", "w", stdout);
	vector<string> inp;
	string temp;
	while (cin >> temp)
	{
		inp.pb(temp);
	}
	ll ans = 0;
	for (auto s : inp)
	{
		stack<char> stk;
		for (auto c : s)
		{
			if (c == '(' || c == '[' || c == '{' || c == '<')
			{
				stk.push(c);
			}
			else
			{
				char t = stk.top();
				stk.pop();
				if (!((t == '(' && c == ')') || (t == '[' && c == ']') || (t == '{' && c == '}') || (t == '<' && c == '>')))
				{
					if (c == ')')
					{
						ans += 3;
					}
					else if (c == ']')
					{
						ans += 57;
					}
					else if (c == '}')
					{
						ans += 1197;
					}
					else if (c == '>')
					{
						ans += 25137;
					}
					break;
				}
			}
		}
	}
	/**
	for (auto s : inp)
	{
		vi co(4, 0);
		for (auto c : s)
		{
			if (c == '(')
			{
				co[0]++;
			}
			else if (c == ')')
			{
				co[0]--;
			}
			else if (c == '[')
			{
				co[1]++;
			}
			else if (c == ']')
			{
				co[1]--;
			}
			else if (c == '{')
			{
				co[2]++;
			}
			else if (c == '}')
			{
				co[2]--;
			}
			else if (c == '<')
			{
				co[3]++;
			}
			else if (c == '>')
			{
				co[3]--;
			}
			bool flag = false;
			for (auto x : co)
			{
				if (x < 0)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				if (c == ')')
				{
					ans += 3;
				}
				else if (c == ']')
				{
					ans += 57;
				}
				else if (c == '}')
				{
					ans += 1197;
				}
				else if (c == '>')
				{
					ans += 25137;
				}
			}
		}
	}
	**/
	cout << ans;
	return 0;
}
