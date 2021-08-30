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
typedef unsigned long long int ull;
typedef long double ld;
//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vvi> trie(32, vi(26, vi(26, 0)));
    for (int i = 0; i < n; i++)
    {
        string token;
        cin >> token;
        for (int j = 0; j < token.length()-1; j++)
        {
            trie[j][token[j] - 97][token[j+1]-97]++;
        }
        cout << 
    }
    return 0;
}