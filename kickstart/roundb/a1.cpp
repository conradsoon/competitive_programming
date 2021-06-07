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
    for (int j = 1; j <= t; j++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << "Case #" << j << ": 1 ";
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if ((int)s[i] > (int)s[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            cout << count << " ";
        }
        cout << "\n";
    }
    return 0;
}