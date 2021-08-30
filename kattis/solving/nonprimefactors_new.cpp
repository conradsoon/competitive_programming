#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <string.h>
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
vector<int> SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    vector<int> primes;
    primes.reserve(150000);
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
    return primes;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    vector<int> primes = SieveOfEratosthenes(2 * 1000000 + 1);
    while (q--)
    {
        int i;
        cin >> i;
        unordered_map<int, int> factors;
        for (int it = 0; i != 1; it++)
        {
            while (i % primes[it] == 0)
            {
                i /= primes[it];
                factors[primes[it]]++;
            }
        }
        ll no_factors = 1;
        for (auto it : factors)
        {
            no_factors *= (it.second + 1);
        }
        no_factors -= factors.size();
        cout << no_factors << "\n";
    }
    return 0;
}