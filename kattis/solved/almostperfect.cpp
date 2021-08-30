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

vector<int> dvsrs(int n)
{
    vector<int> factors;
    factors.push_back(1);
    // Print the number of 2s that divide n
    // one element (Note i = i +2)
    for (int i = 2; i <= sqrt(n); i++)
    {
        // While i divides n, print i and divide n
        if (n % i == 0)
        {
            factors.push_back(i);
            factors.push_back(n/i);
        }
    }
    return factors;
}
//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n)
    {
        int sum_of_primes = 0;
        int diff;
        vector<int> divisors = dvsrs(n);
        for (auto i : divisors)
        {
            sum_of_primes += i;
        }
        diff = abs(sum_of_primes - n);
        cout << n << ((diff <= 2) ? (diff == 0 ? " " : " almost ") : " not ") << "perfect\n";
    }
    return 0;
}