#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
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

const int MAX = 1000001;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<bool> h_prime(250001, true); //value corresponds to 4*index + 1
    h_prime[0] = false;
    for (int i = 1; i <= 250000; i++)
    {
        if (h_prime[i])
        {
            int j = 4 * i + 1;
            int idx = i + j;
            while (idx <= 250000)
            {
                h_prime[idx] = false;
                idx += j;
            }
        }
    }

    vector<long> p;
    set<long> sp; //take note factorisation in S is non-unique
    for (int i = 1; i <= 250000; i++)
    {
        if (h_prime[i])
        {
            p.push_back(4*i+1);
        }
    }
    for(auto it1 = p.begin(); it1 != p.end(); it1++){
        for(auto it2 = it1; it2 != p.end(); it2++){
            long num = (*it1)*(*it2);
            if(num > MAX){
                break;
            }
            else{
                sp.insert(num);
            }
        }
    }
    vector<long> sp_vector(sp.begin(),sp.end()); //because set doesn't have pointer arithmetic
    int n;
    while (cin >> n && n != 0)
    {
        cout << n << " " << upper_bound(sp_vector.begin(),sp_vector.end(), n) - sp_vector.begin() << "\n";
    }
    return 0;
}