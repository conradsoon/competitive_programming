#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
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
    int n, t;
    vector<unsigned int> a;
    cin >> n >> t;
    a.reserve(n);
    while (n--)
    {
        unsigned int inp;
        cin >> inp;
        a.push_back(inp);
    }
    switch (t)
    {
    case 1:
    {
        cout << 7;
        break;
    }
    case 2:
    {
        cout << ((a[0] > a[1]) ? "Bigger" : (a[0] == a[1] ? "Equal" : "Smaller"));
        break;
    }
    case 3:
    {
        int median = a[0];
        vector<unsigned int> list;
        list.push_back(a[0]);
        list.push_back(a[1]);
        list.push_back(a[2]);
        sort(list.begin(), list.end());
        cout << list[1];
        break;
    }
    case 4:
    {
        ll sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            sum += a[i];
        }
        cout << sum;
        break;
    }
    case 5:
    {
        ll sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] % 2 == 0)
            {
                sum += a[i];
            };
        }
        cout << sum;
        break;
    }
    case 6:
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << (char)(a[i] % 26 + 97);
        }
        break;
    }
    case 7:
    {
        unsigned int t = 0; //tortoise
        unsigned int h = 0; //hare
        while (true)
        {
            t = a[t];
            h = a[h];
            if (h >= a.size())
            {
                cout << "Out";
                break;
            }
            h = a[h];
            if (h >= a.size())
            {
                cout << "Out";
                break;
            }
            if (t == a.size() - 1)
            {
                cout << "Done";
                break;
            }
            if (t == h)
            {
                cout << "Cyclic";
                break;
            }
        }
        break;
    }
    }
    return 0;
}