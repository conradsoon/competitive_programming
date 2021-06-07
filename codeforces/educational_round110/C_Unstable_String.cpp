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
bool match(char lhs, char rhs)
{
    if (lhs == '?' || rhs == '?')
    {
        return true;
    }
    else
    {
        return !(lhs == rhs);
    }
}
void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    vector<pair<ll, ll>> b;
    ll p1 = 0, p2 = 0;
    char last_char = '?';
    for (; p2 < n; p2++)
    {
        if (match(last_char, s[p2]))
        {
            if (s[p2] == '?')
            {
                if (last_char == '1')
                {
                    last_char = '0';
                }
                else if (last_char == '0')
                {
                    last_char = '1';
                }
                else
                {
                    last_char = '?';
                }
            }
            else
            {
                last_char = s[p2];
            }
        }
        else
        {
            p2--;
            b.push_back({p1, p2});
            p1 = p2;
            while (s[p1] == '?')
            {
                p1--;
            }
            p1++;
            last_char = '?';
        }
    }
    b.push_back({p1, p2 - 1});
    ull count = 0;
    for (auto pr : b)
    {
        ll l = pr.second - pr.first + 1;
        count += (l) * (l + 1) / 2;
    }
    for (ll i = 1; i < b.size(); i++)
    {
        ll overlap = b[i - 1].second - b[i].first + 1;
        if (overlap >= 0)
        {
            count -= overlap * (overlap + 1) / 2;
        }
    }
    cout << count << "\n";
}
//template ends
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}