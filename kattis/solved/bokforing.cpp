#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
    int n, q;
    cin >> n>> q;
    string command;
    int dflt = 0;
    unordered_map<int,int> vals_set;
    while (q--)
    {
        cin >> command;
        if (command == "SET")
        {
            int a, b;
            cin >> a >> b;
            vals_set[a] = b;
        }
        else if (command == "PRINT")
        {
            int a;
            cin >> a;
            if(vals_set.find(a) == vals_set.end()){
                cout << dflt << "\n";
            }
            else{
                cout << vals_set[a] << "\n";
            }
        }
        else if (command == "RESTART")
        {
            vals_set.clear();
            cin >> dflt;
        }
    }
    return 0;
}