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
#define MAX 2000001
int main()
{
    //with reference to https://github.com/mpfeifer1/Kattis/blob/master/nonprimefactors.cpp
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> no_primes(MAX + 5, 0);
    vector<int> no_divisors(MAX + 5, 1);
    for (int i = 2; i < no_primes.size(); i++)
    {
        if (no_primes[i] == 0)
        {
            for (int no = i; no <= MAX; no += i)
            {
                no_primes[no]++;
                int a = no;
                int it = 0;
                while (a % i == 0)
                {
                    a /= i;
                    it++;
                }
                no_divisors[no] *= (it + 1);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int i;
        cin >> i;
        cout << no_divisors[i] - no_primes[i] << "\n";
    }

    return 0;
}