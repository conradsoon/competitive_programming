
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
string findBeautiful(string s, int k)
{
    set<char> seen;
    int i = 0;
    bool beautiful = true;
    for (auto c : s)
    {
        if (seen.find(c) == seen.end() && seen.size() >= k)
        {
            beautiful = false;
            break;
        }
        seen.insert(c);
        i++;
    }
    if (beautiful)
    {
        return s;
    }
    else
    {
        char max_dig = '0';
        for (int j = i; j < s.size(); j++)
        {
            max_dig = max(max_dig, s[j]);
        }
        if (max_dig > *seen.rbegin())
        {
            string _s = s.substr(0, i + 1);
            _s = to_string(stoll(_s) + 1);
            while (_s.size() < s.size())
            {
                _s += '0';
            }
            return findBeautiful(_s, k);
        }
        else
        {
            s[i] = *seen.lower_bound(s[i]);
            for (int j = i + 1; j < s.size(); j++)
            {
                s[j] = *seen.begin();
            }
            return s;
        }
    }
}
void solve()
{
    string s;
    int k;
    cin >> s >> k;
    cout << findBeautiful(s, k) << "\n";
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