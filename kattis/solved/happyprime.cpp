#include <iostream>
#include <string>
#include <vector>
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
int iter_happy(int n)
{
    string num = to_string(n);
    int sum = 0;
    for (char i : num)
    {
        sum += stoi(string(1, i)) * stoi(string(1, i));
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p;
    cin >> p;
    int n = 10000;
    bool prime[n + 1];
    vi happy(n + 1);
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int t = iter_happy(i);
        int h = iter_happy(t);
        while (t != h)
        {
            t = iter_happy(t);
            h = iter_happy(iter_happy(h));
        }
        if (t == 1)
        {
            happy[i] = true;
        }
    }
    while (p--)
    {
        int a, b;
        cin >> a >> b;
        bool is_happy_prime = prime[b] && happy[b];
        cout << a << " " << b << " " << (is_happy_prime ? "YES\n" : "NO\n");
    }
    return 0;
}