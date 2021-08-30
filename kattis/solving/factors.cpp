#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
    const vector<ull> factors = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    stack<ull> test_no;
    test_no.push(1ULL);
    ull max = 1ULL << 63;
    vector<ull> n_list;
    ull n;
    while (cin >> n)
    {
        if (n == 1) //corner case
        {
            cout << 2 << "\n";
        }
        else
        {
        }
    }
    return 0;
}