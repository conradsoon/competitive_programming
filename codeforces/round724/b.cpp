
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
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<string> substrings;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            substrings.insert(s.substr(j, i));
        }
        int test = 1 + 2;
    }
    bool not_found = true;
    string mex;
    //substrings of length 1
    if (not_found)
    {
        for (int i = 0; i < 26; i++)
        {
            if (!not_found)
            {
                break;
            }
            mex = char('a' + i);
            if (substrings.find(mex) == substrings.end())
            {
                not_found = false;
                break;
            }
        }
    }
    //substrings of length 2
    if (not_found)
    {
        for (int i = 0; i < 26; i++)
        {
            if (!not_found)
            {
                break;
            }
            for (int j = 0; j < 26; j++)
            {
                if (!not_found)
                {
                    break;
                }
                mex = char('a' + i);
                mex += char('a' + j);
                if (substrings.find(mex) == substrings.end())
                {
                    not_found = false;
                    break;
                }
            }
        }
    }
    //length 3
    if (not_found)
    {
        mex = "";
        for (int i = 0; i < 26; i++)
        {
            if (!not_found)
            {
                break;
            }
            for (int j = 0; j < 26; j++)
            {
                if (!not_found)
                {
                    break;
                }
                for (int k = 0; k < 26; k++)
                {
                    if (!not_found)
                    {
                        break;
                    }
                    mex = char('a' + i);
                    mex += char('a' + j);
                    mex += char('a' + k);
                    if (substrings.find(mex) == substrings.end())
                    {
                        not_found = false;
                        break;
                    }
                }
            }
        }
    }
    cout << mex << "\n";
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