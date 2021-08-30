// C++ program to print all prime factors  
#include <bits/stdc++.h>
#include <unordered_map> 
using namespace std; 
  
// A function to print all prime  
// factors of a given number n
//unoptimised
map<ll, ll> primeFactors(ll n)
{
    map<ll, ll> fac;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            n /= i;
            fac[i]++;
        }
    }
    if (n > 1)
    {
        fac[n]++;
    }
    return fac;
} 
//optimised
vector<long long> trial_division2(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}