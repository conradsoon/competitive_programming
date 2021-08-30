
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
int find(vi &a, int num)
{
	int i = 0;
	while (a[i] != num)
	{
		i++;
	}
	return i;
}
bool isSorted(vi &a, int size)
{
	bool sorted = true;
	for (int i = 0; i < size; i++)
	{
		if (a[i] != i + 1)
		{
			sorted = false;
			break;
		}
	}
	return sorted;
}
void solve()
{
	int n;
	cin >> n;
	vi a(n);
	for (auto &c : a)
	{
		cin >> c;
	}
	//got in even?
	bool hasWrongParity = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (((a[i] % 2) ^ ((i + 1) % 2)))
		{
			hasWrongParity = true;
			break;
		}
	}
	if (hasWrongParity)
	{
		cout << "-1\n";
	}
	else
	{
		int curr_seg = a.size();
		vi ans;
		while (!isSorted(a, curr_seg))
		{
			int top_idx = find(a, curr_seg);
			reverse(a.begin(), a.begin() + top_idx + 1);
			ans.push_back(top_idx + 1);
			int s_top_idx = find(a, curr_seg - 1);
			reverse(a.begin(), a.begin() + s_top_idx);
			ans.push_back(s_top_idx);
			reverse(a.begin(), a.begin() + s_top_idx + 2);
			ans.push_back(s_top_idx + 2);
			reverse(a.begin(), a.begin() + 3);
			ans.push_back(3);
			reverse(a.begin(), a.begin() + curr_seg);
			ans.push_back(curr_seg);
			curr_seg -= 2;
		}
		cout << ans.size() << "\n";
		for (auto c : ans)
		{
			cout << c << " ";
		}
		cout << "\n";
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