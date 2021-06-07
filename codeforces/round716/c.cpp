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
    int n;
    cin >> n;
    vi cprme;
    //im fucking lazy
    ll lazy = 1;
    for (int i = 1; i < n; i++)
    {
        if (__gcd(i, n) == 1)
        {
            cprme.push_back(i);
            lazy = (lazy * i) % n;
        }
    }
    if (lazy == n - 1 && n > 2)
    {
        cprme.pop_back();
    }
    cout << cprme.size() << "\n";
    for (int i = 0; i < cprme.size(); i++)
    {
        cout << cprme[i] << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}