#include <iostream>
#include <string>
#include <vector>
#include <math.h>
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

//https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
//https://blog.csdn.net/A775700879/article/details/16368377
//if tle at 5/6th case need to change from decimal to hundredary/thousandary/more system
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int N = 1000005;
    int lp[N + 1];
    vector<int> pr;
    
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }

    string num;
    ull l;

    const ull break_up = 13;
    ull base = 1;
    for (ull i = 0; i < break_up; i++)
    {
        base *= 10;
    }

    while (cin >> num >> l && l != 0)
    {
        reverse(num.begin(), num.end());
        bool is_good = true;
        ull last_factor;
        vector<ull> broken_num((num.size() + break_up - 1) / break_up, 0);
        ull place = 1;
        for (ull n = 0; n < break_up; n++)
        {
            for (ull i = 0; i + n < num.size(); i += break_up)
            {
                broken_num[i / break_up] += (num[i + n] - '0') * place;
            }
            place *= 10;
        }

        ull until = lower_bound(pr.begin(), pr.end(), l) - pr.begin();
        for (ull i = 0; i < until; i++)
        {
            ull p = (ull) pr[i];
            last_factor = p;
            ull place_mod = 1;
            ull sum = 0;
            for (auto dig : broken_num)
            {
                sum = (sum + place_mod * dig) % p;
                place_mod = (place_mod * base) % p;
            }
            if (sum == 0)
            {
                is_good = false;
                break;
            }
        }
        if (is_good)
        {
            cout << "GOOD\n";
        }
        else
        {
            cout << "BAD " << last_factor << "\n";
        }
    }
    return 0;
}