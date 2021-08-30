#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <numeric>
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

//template ends
unordered_map<int, int> primeFactors(int n)
{
    unordered_map<int, int> factors;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        factors[2]++;
        n /= 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            factors[i]++;
            n /= i;
        }
    }
    if (factors.find(n) == factors.end() && n > 2)
    {
        factors[n]++;
    }
    return factors;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int input;
    while (cin >> input && input != 0)
    {
        int neg = 1;
        if (input < 0)
            neg = -1;
        unordered_map<int, int> factors = primeFactors(neg * input);
        vector<int> powers;
        for (auto element : factors)
        {
            powers.push_back(element.second);
        }
        int d = *powers.begin();
        for (auto it = powers.begin() + 1; it != powers.end(); it++)
        {
            d = __gcd(d, *it);
        }
        if (neg == -1)
        {
            //deals with negative numbers
            while(d%2 == 0){
                d/=2;
            }
        }
        cout << d << "\n";
    }
    return 0;
}