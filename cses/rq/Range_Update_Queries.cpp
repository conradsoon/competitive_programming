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
const ll N = 2e5;
ll n; // array size
ull t[2 * N];

void build()
{ // build the tree
    for (ll i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int l, int r, int value)
{
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            t[l++] += value;
        if (r & 1)
            t[--r] += value;
    }
}

ll query(int p)
{
    ll res = 0;
    for (p += n; p > 0; p >>= 1)
        res += t[p];
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin >> n >> q;
    for (ll i = 0; i < n; ++i)
        cin >> t[n + i];
    //build();
    ll type, a, b, c;
    for (ll i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> a >> b >> c;
            modify(a - 1, b, c);
        }
        else if (type == 2)
        {
            cin >> a;
            cout << query(a - 1) << "\n";
        }
    }
    return 0;
}