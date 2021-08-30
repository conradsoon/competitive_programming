#include <iostream>
#include <string>
#include <vector>
#include <sstream>
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

//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    while (k--)
    {
        string prog;
        int n;
        string parse;
        deque<int> list;
        bool error = false;
        bool rvrse = false;
        cin >> prog;
        cin >> n;
        cin >> parse;
        istringstream ss(parse.substr(1, parse.size() - 2));
        string token;
        while (getline(ss, token, ','))
        {
            list.push_back(stoi(token));
        }
        for (auto it = prog.begin(); it != prog.end(); it++)
        {
            if (*it == 'R')
            {
                rvrse = !rvrse; //toggles
            }
            else if (*it == 'D')
            {
                if (list.size() == 0)
                {
                    cout << "error\n";
                    error = true;
                    break;
                }
                else
                {
                    if (rvrse)
                    {
                        list.pop_back();
                    }
                    else
                    {
                        list.pop_front();
                    }
                }
            }
        }
        if (!error)
        {
        cout << '[';
            if (list.size() == 0)
            {
                cout << "]\n";
            }
            else
            {
                if (rvrse)
                {
                    for (auto it = list.rbegin(); it != list.rend() - 1; it++)
                    {
                        cout << *it << ",";
                    }
                    cout << *(list.rend() - 1) << "]\n";
                }
                else
                {
                    for (auto it = list.begin(); it != list.end() - 1; it++)
                    {
                        cout << *it << ",";
                    }
                    cout << *(list.end() - 1) << "]\n";
                }
            }
        }
    }
    return 0;
}