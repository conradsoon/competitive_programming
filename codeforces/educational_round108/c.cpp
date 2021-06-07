
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
    vvi u(n); //ith university student list
    vi s(n);  //which university ith student enrolled in
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i]--;
    }
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        u[s[i]].push_back(temp);
    }
    vector<vector<ll>> pfx(n);
    for (int i = 0; i < n; i++)
    {
        //sort and calc prefix
        if (u[i].size() >= 1)
        {
            sort(u[i].begin(), u[i].end(), greater<int>());
            pfx[i].resize(u[i].size(), 0);
            pfx[i][0] = u[i][0];
            for (int j = 1; j < u[i].size(); j++)
            {
                pfx[i][j] = pfx[i][j - 1] + 1LL * u[i][j];
            }
        }
    }
    vector<ll> psum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int m = min(int(u[i].size()), n);
        for (int k = 1; k <= m; k++)
        {
            psum[k] += pfx[i][u[i].size() - (u[i].size() % k) - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << psum[i] << " ";
    }
    cout << "\n";
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