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
void update(vi &g, vi &revtable, string &s, int idx)
{
    for (; idx > 0; idx >>= 1)
    {
        char r = s[revtable[idx]]; //composition of self inverse permutations results in self inverse permutations
        if (r == '0')
        {
            g[idx] = g[idx << 1];
        }
        else if (r == '1')
        {
            g[idx] = g[(idx << 1) + 1];
        }
        else if (r == '?')
        {
            g[idx] = g[idx << 1] + g[(idx << 1) + 1];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    vi g((1 << (k + 1)), 1);
    string temp;
    cin >> temp;
    string s = "X"; //filler X at start to line up indices
    s += temp;

    vi table(1 << k); //lookup table
    iota(table.begin() + 1, table.end(), 1);
    reverse(table.begin() + 1, table.end());
    auto it = table.begin() + 1;
    int l = 1 << (k - 1);
    for (; l > 0; it += l, l >>= 1)
    {
        reverse(it, it + l);
    }

    vi revtable(1 << k); //reverse lookup table
    for (int i = 1; i < revtable.size(); i++)
    {
        revtable[table[i]] = i;
    }
    //build
    for (int i = 1; i < s.size(); i++)
    {
        update(g, revtable, s, table[i]);
    }

    //queries
    int p, q;
    cin >> q;
    char c;
    for (int i = 0; i < q; i++)
    {
        cin >> p >> c;
        s[p] = c;
        update(g, revtable, s, table[p]);
        cout << g[1] << "\n";
    }
    return 0;
}
