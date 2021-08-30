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

//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b ,c;
    cin >> a >> b >> c >> n;
    if(a*b*c != 0 && a+b+c >= n && n >= 3){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}