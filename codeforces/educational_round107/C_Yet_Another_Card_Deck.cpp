
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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int temp;
    for (int i = 0; i < q; i++)
    {
        cin >> temp;
        auto it = find(a.begin(), a.end(), temp);
        cout << it - a.begin() + 1 << " ";
        for (; it != a.begin(); it--)
        {
            swap(*(it - 1), *(it));
        }
    }
    return 0;
}