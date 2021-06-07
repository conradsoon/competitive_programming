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
    int n;
    cin >> n;
    vi a(n + 1);
    vi b(n + 1);
    vi c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        m[b[c[i]]]++;
    }
    ull count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += m[a[i]];
    }
    cout << count;
    return 0;
}