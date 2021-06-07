#include <bits/stdc++.h>
#include <stack>
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
void solve()
{
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool possible = true;
    int p = 0;
    stack p_pos;
    for (int i = 0; i < s.length() / 2; i++)
    {
        if ((s[i] == '1' && s[s.length() - i - 1] == '0') || (s[i] == '0' && s[s.length() - i - 1] == '1'))
        {
            possible = false;
            break;
        }
        else if (s[i] == '0' && s[s.length() - i - 1] == '0')
        {
            a -= 2;
        }
        else if ((s[i] == '1' && s[s.length() - i - 1] == '1'))
        {
            b -= 2;
        }
        else if ((s[i] == '1' && s[s.length() - i - 1] == '?') || (s[i] == '?' && s[s.length() - i - 1] == '1'))
        {
            s[i] = '1';
            s[s.length() - i - 1] = '1';
            b -= 2;
        }
        else if ((s[i] == '0' && s[s.length() - i - 1] == '?') || (s[i] == '?' && s[s.length() - i - 1] == '0'))
        {
            s[i] = '0';
            s[s.length() - i - 1] = '0';
            a -= 2;
        }
        else if ((s[i] == '?' && s[s.length() - i - 1] == '?') || (s[i] == '?' && s[s.length() - i - 1] == '?'))
        {
            p += 2;
            p_pos.push(i);
        }
    }
    //check for middle
    if (s.length() % 2 == 1)
    {
        switch (s[s.length() / 2])
        {
        case '0':
            a--;
            break;
        case '1':
            b--;
            break;
        case '?':
            p++;
            break;
        }
    }
    for (int i = 0; i < a / 2; i++)
    {
        s[p_pos.top()] = '0';
        p -= 2;
    }
    for (int i = 0; i < b / 2; i++)
    {
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