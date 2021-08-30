#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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
    ld c;
    cin >> c;
    cout << setprecision(10);
    if (c >= 1)
    {
        cout << 0.25;
    }
    else
    {
        //question boils down to maximizing xy given constraint of x + y = c if c <= 1 or x + y = 1 if not
        //optimal solution given by method of lagrange multipliers
        cout << (c / 2) * (c / 2);
    }
    return 0;
}