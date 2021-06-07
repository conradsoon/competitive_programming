#include <bits/stdc++.h>
#include <unordered_map>
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        auto f = a.begin();
        auto s = a.begin() + 1;
        if (*s != *f)
        {
            auto t = s + 1;
            if (*t == *f)
            {
                cout << "2\n";
            }
            else if (*t == *s)
            {
                cout << "1\n";
            }
        }
        else
        {
            while (*s == *f)
            {
                s++;
            }
            cout << (s - f) + 1 << "\n";
        }
    }
    return 0;
}