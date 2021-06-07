#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
//template ends
bool is_palindrome(string s)
{
    bool is_p = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[s.length() - 1 - i])
        {
            is_p = false;
            break;
        }
    }
    return is_p;
}
int count_zeros(string s)
{
    int count = 0;
    for (auto c : s)
    {
        if (c == '0')
        {
            count++;
        }
    }
    return count;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zeros = count_zeros(s);
    if (is_palindrome(s))
    {
        if (zeros == 1)
        {
            cout << "BOB\n";
        }
        else
        {
            if (zeros % 2 == 0)
            {
                cout << "BOB\n";
            }
            else if (zeros % 2 == 1)
            {
                cout << "ALICE\n";
            }
        }
    }
    else
    {
        if (n % 2 == 1 && s[n / 2] == '0' && zeros == 2)
        {
            cout << "DRAW\n";
        }
        else
        {
            cout << "ALICE\n";
        }
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