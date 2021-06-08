
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
    string s;
    cin >> s;
    vi one_indices;
    one_indices.reserve(n);
    vi zero_indices;
    zero_indices.reserve(n);
    string seq1(n, 'x');
    string seq2(n, 'x');
    bool possible = true;
    if (s[0] != '1' || s[n - 1] != '1')
    {
        possible = false;
    }
    int no_zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero_indices.push_back(i);
            no_zero++;
        }
        else if (s[i] == '1')
        {
            one_indices.push_back(i);
        }
    }
    if (no_zero % 2 == 1)
    {
        possible = false;
    }
    if (possible)
    {
        for (int i = 0; i < one_indices.size() / 2; i++)
        {
            seq1[one_indices[i]] = '(';
            seq1[one_indices[one_indices.size() - i - 1]] = ')';
            seq2[one_indices[i]] = '(';
            seq2[one_indices[one_indices.size() - i - 1]] = ')';
        }
        for (int i = 0; i < zero_indices.size(); i++)
        {
            if (i % 2 == 0)
            {
                seq1[zero_indices[i]] = '(';
                seq2[zero_indices[i]] = ')';
            }
            else
            {
                seq1[zero_indices[i]] = ')';
                seq2[zero_indices[i]] = '(';
            }
        }
        cout << "YES\n";
        cout << seq1 << "\n";
        cout << seq2 << "\n";
    }
    else
    {
        cout << "NO\n";
    }
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