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
void solve()
{
    string s;
    string max_s;
    cin >> s;
    unordered_map<char, int> freq;
    unordered_map<char, bool> bunched;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
        bunched[s[i]] = true;
    }
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
        bunched[s[i]] = true;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (freq[s[i]] != 0)
        {
            int j = i;
            char max_c = 'A'; //guaranteed smaller
            while (freq[s[j]] != 1)
            {
                if (s[j] >= max_c && freq[s[j]] != 0)
                {
                    freq[max_c]--;
                    max_c = s[j];
                }
                j++;
            }
            if (s[j] >= max_c)
            {
                freq[max_c]--;
            }
            max_c = max(max_c, s[j]);
            freq[max_c] = 0;
            max_s.push_back(max_c);
        }
    }
    cout << max_s << "\n";
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