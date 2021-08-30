#include <iostream>
#include <string>
#include <vector>
#include <math.h>
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
    ll n, m, a;
    cin >> n >> m >> a;
    if (a % n == 0 || a % m == 0)
    {
        cout << 1;
    }
    else
    {
        bool is_3 = true;
        for (ll i = 1; i <= n; i++)
        {
            if (a % i == 0 && (a/i) <= m)
            {
                cout << 2;
                is_3 = false;
                break;
            }
            if ((n*m-a) % i == 0 && ((n*m-a)/i) <= m)
            {
                cout << 2;
                is_3 = false;
                break;
            }
        }
        if(is_3){
            cout << 3;
        }
    }
    return 0;
}