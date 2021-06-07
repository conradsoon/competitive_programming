
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
void solve()
{
    int n;
    cin >> n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vi b;
    b.reserve(n);
    b.push_back(1);
    for (int i = p[1]; i != 1; i = p[i])
    {
        b.push_back(i);
    }
    cout << b[k % b.size()];
    return 0;
}