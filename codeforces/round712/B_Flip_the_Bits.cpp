
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
string xr(string a, string b)
{
    string c;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            c.push_back('1');
        }
        else
        {
            c.push_back('0');
        }
    }
    return c;
}

void solve()
{
    int n;
    cin >> n;
    string inp;
    string out;
    cin >> inp >> out;
    int ni1 = 0;
    set<int> possible_indices;
    for (int i = 0; i < n; i++)
    {
        if (inp[i] == '1')
        {
            ni1++;
        }
        if (ni1 == i + 1 - ni1)
        {
            possible_indices.insert(i);
        }
    }
    string diff = xr(inp, out);
    set<int> req_indices;
    char prev_char = '0'; //placeholder
    for (int i = n - 1; i >= 0; i--)
    {
        if (diff[i] != prev_char)
        {
            req_indices.insert(i);
            prev_char = diff[i];
        }
    }
    bool possible = true;
    for (auto s : req_indices)
    {
        if (possible_indices.find(s) == possible_indices.end())
        {
            possible = false;
            break;
        }
    }
    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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