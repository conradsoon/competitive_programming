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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> s;
        s.reserve(n);
        for (int i = 0; i < n; i++)
        {
            char temp;
            cin >> temp;
            if (temp == '*')
            {
                s.push_back(i);
            }
        }
        int m = (s.size()) / 2;
        ll count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            count += abs(s[m] - s[i] - (m - i));
        }
        cout << count << "\n";
        cin.ignore(1);
    }
    return 0;
}