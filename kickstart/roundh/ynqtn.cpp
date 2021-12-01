#include <bits/stdc++.h>

using namespace std;
vector<string> ans;
vector<string> pans;
int sq;
int d;
int rn;
int cn;
int k;

vector<vector<bool>> st;
vector<vector<char>> an;
string prb(vector<vector<char>> a)
{
	string s = "";
	for (auto l : a)
	{
		for (auto c : l)
		{
			s += c;
		}
		s += "\n";
	}
	return s;
}

void f()
{
	if (!ans.empty())
	{
		return;
	}
	int r = sq / cn;
	int c = sq % rn;
	if (d == k)
	{
		ans.push_back(prb(an));
		return;
	}
	if (sq == rn * cn)
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
	cin >> rn >> cn;
	if (rn % 2)
	{
		swap(rn, cn);
	}
	k = rn * ((cn + 1) / 2);
	while (true)
	{
		sq = 0;
		d = 0;
		st.assign(rn + 1, vector<bool>(cn + 1, false));
		an.assign(rn, vector<char>(cn, 'x'));
		f();
		if (ans.empty())
		{
			break;
		}
		swap(ans, pans);
		ans.clear();
		k++;
	}
	k--;
	cout << k << "\n";
	for (auto a : pans)
	{
		cout << a << "\n";
	}
	return 0;
}