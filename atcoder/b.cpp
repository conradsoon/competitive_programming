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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    string new_s(s.length(), 0);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            new_s[s.length() - 1 - i] = '0';
        }
        else if (s[i] == '1')
        {
            new_s[s.length() - 1 - i] = '1';
        }
        else if (s[i] == '8')
        {
            new_s[s.length() - 1 - i] = '8';
        }
        else if (s[i] == '6')
        {
            new_s[s.length() - 1 - i] = '9';
        }
        else if (s[i] == '9')
        {
            new_s[s.length() - 1 - i] = '6';
        }
    }
    cout << new_s;
    return 0;
}