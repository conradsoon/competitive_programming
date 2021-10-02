
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string T;
	cin >> N >> T;
	string S;
	cin >> S;
	ll L = 0;
	for (auto c : S)
	{
		if (c == '1')
		{
			L++;
		}
	}
	if (T.size() > 8)
	{
		if (L >= 2)
		{
			cout << 0 << "\n";
		}
		else if (L == 1)
		{
			cout << 1 << "\n";
		}
		else
		{
			if (N % 2)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}
	else
	{
		ll T_val = stoll(T);
		ll help = T_val - L;
		if (T_val % 2)
		{
			cout << "0\n";
		}
		else if (T_val < 0)
		{
			cout << "0\n";
		}
		else
		{
			if (L >= 2)
			{
				cout << 0 << "\n";
			}
			else if (L == 1)
			{
				cout << 1 << "\n";
			}
			else
			{
				if (N % 2)
				{
					cout << 1 << "\n";
				}
				else
				{
					cout << 0 << "\n";
				}
			}
		}
	}
	return 0;
}