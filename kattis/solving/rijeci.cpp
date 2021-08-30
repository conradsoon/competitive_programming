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
void iter(pii &x)
{
    int a = x.first;
    int b = x.second;
    x.first = b;
    x.second = a + b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pii x = {1, 0};
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        iter(x);
    }
    cout << x.first << " " << x.second;
    return 0;
}