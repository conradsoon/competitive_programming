#include <iostream>
#include <string>
#include <vector>
#include <deque>

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
//https://stackoverflow.com/questions/62888076/creating-a-custom-data-structure-teque-with-arrays-in-java
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    deque<int> front;
    deque<int> back;
    while (n--)
    {
        string com;
        int arg;
        cin >> com >> arg;
        if (com == "push_front")
        {
            front.push_front(arg);
        }
        else if (com == "push_middle")
        {
            back.push_front(arg);
        }
        else if (com == "push_back")
        {
            back.push_back(arg);
        }
        else if (com == "get")
        {
        }

    }
    return 0;
}