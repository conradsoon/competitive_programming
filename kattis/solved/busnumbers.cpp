#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
void prtnum(int s, int e)
{
    if (s == e)
    {
        cout << s << " ";
    }
    else if (e - s == 1)
    {
        cout << s << " " << e << " ";
    }
    else
    {
        cout << s << "-" << e << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    int s = b[0];
    int e = b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i] - e > 1)
        {
            prtnum(s, e);
            s = b[i];
            e = b[i];
        }
        else
        {
            e = b[i];
        }
    }
    prtnum(s, e);
    return 0;
}