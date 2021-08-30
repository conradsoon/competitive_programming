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

int fact_pow(int n, int k)
{
    int res = 0;
    while (n)
    {
        n /= k;
        res += n;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll no_2 = 0;
    ll no_5 = 0;
    ll f = 1;
    for (ll i = n; i >= 1; i--)
    {
        ll a = i;
        while (a % 2 == 0)
        {
            a /= 2;
            no_2++;
        }
        while (a % 5 == 0)
        {
            a /= 5;
            no_5++;
        }
        f = (a * f) % 1000;
    }
    ll make_up = no_2 - no_5;
    while (make_up--)
    {
        f = (f * 2) % 1000;
    }
    string f_string = to_string(f);
    if(n>6 && f_string.length()<3){
        while(f_string.length() < 3){
            f_string.insert(0,"0");
        }
    }
    cout << f_string;
    return 0;
}