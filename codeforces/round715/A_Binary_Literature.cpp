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
int count_zeros(string s)
{
    int zeros = 0;
    for (auto c : s)
    {
        if (c == '0')
        {
            zeros++;
        }
    }
    return zeros;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> s(3);
    vi zeros(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
        zeros[i] = count_zeros(s[i]);
    }
    int s1, s2;
    char freq_char;
    if (zeros[0] >= n && zeros[1] >= n)
    {

        s1 = 0;
        s2 = 1;
        freq_char = '0';
    }
    else if (zeros[1] >= n && zeros[2] >= n)
    {

        s1 = 1;
        s2 = 2;
        freq_char = '0';
    }
    else if (zeros[0] >= n && zeros[2] >= n)
    {

        s1 = 0;
        s2 = 2;
        freq_char = '0';
    }
    else if (zeros[0] <= n && zeros[1] <= n)
    {

        s1 = 0;
        s2 = 1;
        freq_char = '1';
    }
    else if (zeros[1] <= n && zeros[2] <= n)
    {

        s1 = 1;
        s2 = 2;
        freq_char = '1';
    }
    else if (zeros[0] <= n && zeros[2] <= n)
    {

        s1 = 0;
        s2 = 2;
        freq_char = '1';
    }
    int k;
    if (freq_char = '0')
    {
        k = min(zeros[s1], zeros[s2]);
    }
    else if (freq_char = '1')
    {
        k = min(2 * n - zeros[s1], 2 * n - zeros[s2]);
    }
    vi s1_i, s2_i;
    s1_i.push_back(-1);
    s2_i.push_back(-1);
    for (int i = 0; s1_i.size() <= k; i++)
    {
        if (s[s1][i] == freq_char)
        {
            s1_i.push_back(i);
        }
    }
    for (int i = 0; s2_i.size() <= k; i++)
    {
        if (s[s2][i] == freq_char)
        {
            s2_i.push_back(i);
        }
    }
    s1_i.push_back(2 * n);
    s2_i.push_back(2 * n);
    string bs;
    for (int i = 0; i < k + 1; i++)
    {
        int itvl = s1_i[i + 1] - s1_i[i] - 1;
        if (itvl < 0)
        {
            itvl = 0;
        }
        bs += s[s1].substr(s1_i[i] + 1, itvl);
        itvl = s2_i[i + 1] - s2_i[i] - 1;
        if (itvl < 0)
        {
            itvl = 0;
        }
        bs += s[s2].substr(s2_i[i] + 1, itvl);
        bs += freq_char;
    }
    bs.pop_back();
    cout << bs << "\n";
}
//template ends
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}