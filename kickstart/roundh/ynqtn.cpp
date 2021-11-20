#include <bits/stdc++.h>

using namespace std;
vector<vector<bool>> st(6, vector<bool>(6, false));
vector<vector<char>> an(5, vector<char>(5, 'x'));
vector<vector<vector<char>>> ans;
int sq = 0;
int d = 0;

void f()
{
	int r = sq / 5;
	int c = sq % 5;
	if (d == 16)
	{
		ans.push_back(an);
		return;
	}
	if (sq == 25)
	{
		return;
	}
	sq++;
	if (!st[r][c + 1] && !st[r + 1][c])
	{
		d++;
		st[r][c + 1] = true;
		st[r + 1][c] = true;
		an[r][c] = '/';
		f();
		d--;
		st[r][c + 1] = false;
		st[r + 1][c] = false;
		an[r][c] = 'x';
	}
	if (!st[r][c] && !st[r + 1][c + 1])
	{
		d++;
		st[r][c] = true;
		st[r + 1][c + 1] = true;
		an[r][c] = '\\';
		f();
		d--;
		st[r][c] = false;
		st[r + 1][c + 1] = false;
		an[r][c] = 'x';
	}
	f();
	sq--;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	f();
	for (auto a : ans)
	{
		for (auto l : a)
		{
			for (auto c : l)
			{
				cout << c;
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}