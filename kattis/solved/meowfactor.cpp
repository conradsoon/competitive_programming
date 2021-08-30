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
typedef unsigned long long int  ull;
typedef long double ld;
//template ends
ull pow9(ull base){
    ull pow_1 = base;
    base *= base;
    base *= base;
    base *= base;
    base *= pow_1;
    return base;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull n;
    cin >> n;
    for(ull i = 128; i >= 1; i--){
        if(n % pow9(i) == 0){
            cout << i;
            break;
        }
    }
    return 0;
}