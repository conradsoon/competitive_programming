#include <iostream>
#include <string>
#include <vector>
#include <map>
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
ull n;
ull a, b, c;
ull x, y;
ull iter_v(ull v, ull r)
{
    return (v * x + r) % y;
}
ull iter_s(ull s)
{
    return (s * b + a) % c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        map<ull, ull> s_vals;
        cin >> n;
        cin >> a >> b >> c;
        cin >> x >> y;
        s_vals[a]++;
        if (n > 1)
        {
            ull t = 0; //tortoise index;
            ull t_val = a;
            ull h = 1;
            ull h_val = iter_s(a);
            s_vals[h_val]++;
            while (t_val != h_val && h < n)
            {
                t++;
                t_val = iter_s(t_val);
                h++;
                h_val = iter_s(h_val);
                s_vals[h_val]++;
                if (h == n - 1)
                {
                    break;
                }
                h++;
                h_val = iter_s(h_val);
                s_vals[h_val]++;
            }
            if (h < n - 1)
            { //periodic
                ull pre_period = t;
                ull period = h - t;
                ull full_cycles = ((n - 1 - pre_period) / period) - 1;
                ull remainder = (n - 1 - pre_period) % period;
                ull it = t_val;
                for (int i = 1; i <= period; i++)
                {
                    s_vals[it] += full_cycles;
                    it = iter_s(it);
                }
                if (remainder > 0)
                {
                    it = t_val;
                    for (int i = 1; i <= remainder; i++)
                    {
                        s_vals[it]++;
                        it = iter_s(it);
                    }
                }
            }
            ull v = 0;
            for (auto it = s_vals.begin(); it != s_vals.end(); it++)
            {
                if ((*it).second > 1)
                {
                    ull t = 0; //tortoise index;
                    ull t_val = v;
                    ull h = 1;
                    ull h_val = iter_v(v, (*it).first);
                    v = h_val;
                    while (t_val != h_val && h <= (*it).second)
                    {
                        t++;
                        t_val = iter_v(t_val, (*it).first);
                        h++;
                        h_val = iter_v(h_val, (*it).first);
                        v = h_val;
                        if (h == (*it).second)
                        {
                            break;
                        }
                        h++;
                        h_val = iter_v(h_val, (*it).first);
                        v = h_val;
                    }
                    if (h < (*it).second)
                    { //periodic
                        ull pre_period = t;
                        ull period = h - t;
                        ull full_cycles = (((*it).second + 1 - pre_period) / period) - 1;
                        ull remainder = ((*it).second + 1 - pre_period) % period;
                        ull its_req = period - remainder;
                        if (remainder == 0)
                        {
                            remainder = period - 1;
                        }
                        v = t_val;
                        for (int i = 1; i <= remainder; i++)
                        {
                            v = iter_v(v, (*it).first);
                        }
                    }
                }
                else
                {
                    v = iter_v(v, (*it).first);
                }
            }
            cout << v << "\n";
        }
        return 0;
    }