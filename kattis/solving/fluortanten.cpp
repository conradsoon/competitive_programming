#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
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
    int n;
    cin >> n;
    vi a(n);
    ll h = 0;
    ll partial = 0;
    ll b = LLONG_MIN;
    int z_i;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            z_i = i;
        }
        h += (ll)(a[i] * (i + 1));
    }
    for (int i = z_i; i < n; i++)
    {
        partial -= a[i];
        b = max(partial, b);
    }
    partial = 0;
    for (int i = z_i; i >= 0; i--)
    {
        partial += a[i];
        b = max(partial, b);
    }
    cout << max(h, h + b);
    return 0;
}