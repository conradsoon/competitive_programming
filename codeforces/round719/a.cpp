#include <bits/stdc++.h>
#include <unordered_set>
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_set<char> seen;
        bool cannot_susp = true;
        if (n == 1)
        {
            cout << "YES\n";
        }
        else
        {
            for (auto it = s.begin() + 1; it != s.end(); it++)
            {
                if (seen.find(*it) != seen.end())
                {
                    cannot_susp = false;
                    break;
                }
                if (*it != *(it - 1))
                {
                    seen.insert(*(it - 1));
                }
            }
            cout << (cannot_susp ? "YES\n" : "NO\n");
        }
    }
    return 0;
}