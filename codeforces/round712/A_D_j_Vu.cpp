
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
bool is_palindrome(string s)
{
    bool palindrome = true;
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}
void solve()
{
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != 'a')
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        if (is_palindrome(s + "a"))
        {

            cout << "a" << s << "\n";
        }
        else
        {

            cout << s << "a\n";
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