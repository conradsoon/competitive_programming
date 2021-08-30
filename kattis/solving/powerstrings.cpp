#include <iostream>
#include <string>
#include <vector>

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
    string s;
    while (cin >> s && s != ".")
    {
        int curr_end = 0;
        int ind = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != s[ind])
            {
                ind = 0;
                curr_end = i;
            }
            else
            {
                ind++;
                ind %= (curr_end + 1);
            }
        }
        if (ind != 0)
        {
            cout << "1\n";
        }
        else
        {
            cout << s.length() / (curr_end + 1) << "\n";
        }
    }
    return 0;
}