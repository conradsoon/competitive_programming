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
    int n, m;
    cin >> n >> m;
    vi clr(n, -1);
    vvi el(n);
    int l = 0;
    bool possible = true;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        el[a].push_back(b);
        el[b].push_back(a);
        if (c == 0)
        {
            clr[a] = 0;
            clr[b] = 0;
        }
        else if (c == 2)
        {
            clr[a] = 1;
            clr[b] = 1;
        }
    }
    return 0;
}