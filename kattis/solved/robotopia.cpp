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
using namespace std;
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    while (n--)
    {
        ll l1, a1, l2, a2, lt, at;
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
        ll det = l1 * a2 - a1 * l2;
        if (det == 0) //implies column 1 and 2 are scalar multiples
        {
            //see if 0 soln or inf soln
            if (l1 * at - a1 * lt == 0)
            {                                //i.e. det of (col 1 result) =0 ==> linear dependence ==> infinite solutions
                if (lt % __gcd(l1, l2) == 0) //does any integer solution exist to diophantine eqn?
                {
                    //brute force to find all positive solns to diophantine eqn because i honestly cant be arsed to read up on diophantine eqns lmao
                    ll no_solns = 0;
                    ll r1;
                    ll r1_it = 1;
                    while (r1_it * l1 <= lt)
                    {
                        if ((lt - (r1_it * l1)) % l2 == 0 && (lt - (r1_it * l1)) / l2 > 0)
                        {

                            r1 = r1_it;
                            no_solns++;
                        }
                        r1_it++;
                    }
                    if (no_solns == 1)
                    {
                        cout << r1 << " " << (lt - r1 * l1) / l2 << "\n";
                    }
                    else
                    {
                        cout << "?\n";
                    }
                }
                else
                {
                    cout << "?\n";
                }
            } //else, not linearly dependent, impossible to solve cus doesnt exist on span of first two linearly dependent columns.
            else
            {
                cout << "?\n";
            }
        }
        else
        {
            //check if solution is integer
            //solving with cramers rule, conveniently allows us to use mod to check if integer and is positive
            ll det_x = lt * a2 - at * l2;
            ll det_y = l1 * at - a1 * lt;
            if ((det_x % det == 0) && (det_y % det == 0) && (det_x / det) > 0 && (det_y / det) > 0)
            {
                cout << det_x / det << " " << det_y / det << "\n";
            }
            else
            {
                cout << "?\n";
            }
        }
    }
    return 0;
}