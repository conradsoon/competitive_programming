#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull tc;
    cin >> tc;
    while (tc--)
    {
        ull n;
        ull a, b, c;
        ull x, y;
        cin >> n;
        cin >> a >> b >> c;
        cin >> x >> y;
        vector<ull> seq(n);
        map<ull, ull> seq_vals;
        seq[0] = a;
        seq_vals[a]++;
        if (n > 1)
        {
            seq[1] = (seq[0] * b + a) % c;
            seq_vals[seq[1]]++;
            ull tortoise = 0;
            ull hare = 1;
            while (seq[tortoise] != seq[hare] && hare < n - 1)
            {
                tortoise++;
                hare++;
                seq[hare] = (seq[hare - 1] * b + a) % c;
                seq_vals[seq[hare]]++;
                if (hare == n - 1)
                {
                    break;
                }
                hare++;
                seq[hare] = (seq[hare - 1] * b + a) % c;
                seq_vals[seq[hare]]++;
            }
            ull pre_period = tortoise;
            ull period = hare - tortoise;
            if (hare < n - 1)
            { //periodic
                ull full_cycles = ((n - 1 - pre_period) / period) - 1;
                ull remainder = (n - 1 - pre_period) % period;
                for (int i = 1; i <= period; i++)
                {
                    seq_vals[seq[pre_period + i]] += full_cycles;
                }
                for (int i = 1; i <= remainder; i++)
                {
                    seq_vals[seq[pre_period + i]]++;
                }
            }
        }
        ull v = 0;
        for (auto it = seq_vals.begin(); it != seq_vals.end(); it++)
        {
            vector<ull> v_seq((*it).second + 1);
            v_seq[0] = v;
            v_seq[1] = (v_seq[0] * x + (*it).first) % y;
            if ((*it).second > 1)
            {
                ull tortoise = 0;
                ull hare = 1;
                while (v_seq[tortoise] != v_seq[hare] && hare < (*it).second)
                {
                    tortoise++;
                    hare++;
                    v_seq[hare] = (v_seq[hare - 1] * x + (*it).first) % y;
                    if (hare == (*it).second)
                    {
                        break;
                    }
                    hare++;
                    v_seq[hare] = (v_seq[hare - 1] * x + (*it).first) % y;
                }
                if (hare < (*it).second)
                { //periodic
                    ull pre_period = tortoise;
                    ull period = hare - tortoise;
                    ull remainder = ((*it).second - pre_period) % period;
                    v = v_seq[pre_period + remainder];
                }
                else
                {
                    v = v_seq.back();
                }
            }
            else
            {
                v = v_seq.back();
            }
        }
        cout << v << "\n";
    }
    return 0;
}