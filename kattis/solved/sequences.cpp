#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define POWER 2;
#define MOD 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string inp;
    cin >> inp;
    int no_q_r = 0;
    int zeros = 0;
    ll sum = 0;
    for (auto i : inp)
    {
        if (i == '0')
        {
            zeros++;
        }
        else if (i == '?')
        {
            no_q_r++;
        }
    }
    ll quarter_seq_no;
    ll half_seq_no;
    ll sequence_no;
    if (no_q_r >= 2)
    {
        quarter_seq_no = 1;
        for (int i = 0; i < no_q_r - 2; i++)
        {
            quarter_seq_no *= 2;
            quarter_seq_no %= MOD;
        }
        half_seq_no = (quarter_seq_no * 2) % MOD;
        sequence_no = (half_seq_no * 2) % MOD;
    }
    else if(no_q_r == 1){
        quarter_seq_no = 0;
        half_seq_no = 1;
        sequence_no = 2;
    }
    else{
        quarter_seq_no = 0;
        half_seq_no = 0;
        sequence_no = 1;
    }
    for (auto i : inp)
    {
        if (i == '0')
        {
            zeros--;
        }
        else if (i == '?')
        {
            no_q_r--;
            sum += half_seq_no * zeros;
            sum %= MOD;
            sum += quarter_seq_no * no_q_r;
            sum %= MOD;
        }
        else if (i == '1')
        {
            sum += sequence_no * zeros;
            sum %= MOD;
            sum += half_seq_no * no_q_r;
            sum %= MOD;
        }
    }
    //initializes powers of two;
    cout << sum;
    return 0;
}