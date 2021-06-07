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
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int curr = 0;
    int msb = 1;
    int l_sum = 0;
    while (n - 1 >> msb)
    {
        msb++;
    }
    for (int i = msb - 1; i >= 0; i--)
    {
        int r = curr | (1 << i) - 1;
        if (r > n - 1)
        {
            r = n - 1;
        }
        int l = curr;
        cout << "? " << l + 1 << " " << r + 1 << "\n";
        cout.flush();
        int a;
        cin >> a;
        a = r - l + 1 - a;
        if (a + l_sum < k)
        {
            curr = r + 1;
            l_sum += a;
        }
    }
    cout << "! " << curr + 1 << "\n";
    return 0;
}