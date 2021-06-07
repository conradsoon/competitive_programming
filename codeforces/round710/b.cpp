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
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> str;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
        {
            str.push_back(i);
        }
    }
    if (str.size() == 1)
    {
        cout << "1\n";
    }
    else if (str.size() == 2)
    {
        cout << "2\n";
    }
    else
    {
        int c = 2;
        //str[0].second = true;
        //*(str.end() - 1).second = true;
        int prev = str[0];
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] - prev > k)
            {
                c++;
                prev = str[i - 1];
                i--;
            }
        }
        cout << c << "\n";
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