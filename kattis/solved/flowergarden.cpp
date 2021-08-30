#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
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
    primes.push_back(0);
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
    return primes;
}

struct pt
{
    ld x;
    ld y;
};

ld dist(const pt &a, const pt &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> primes = SieveOfEratosthenes(30000);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        ld d;
        cin >> n >> d;
        vector<pt> pts(n + 1);
        pts[0] = {0, 0};
        for (int i = 1; i <= n; i++)
        {
            cin >> pts[i].x >> pts[i].y;
        }
        int counter = 0;
        while (counter < n)
        {
            ld test_d = dist(pts[counter], pts[counter + 1]);
            if (test_d > d)
            {
                break;
            }
            else
            {
                d -= test_d;
                counter++;
            }
        }
        cout << *(upper_bound(primes.begin(), primes.end(), counter) - 1) << "\n";
    }
    return 0;
}