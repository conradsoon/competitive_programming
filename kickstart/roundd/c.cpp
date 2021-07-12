
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
//map fuckiness
void solve(ll casenum)
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> itvls;
    ll temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        itvls[temp1] = temp2;
    }
    vll s(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }
    ull diff = 0;
    ll temp3, temp4;
    vll probs;
    for (int i = 0; i < m; i++)
    {
        auto it = itvls.upper_bound(s[i]);
        if (it == itvls.begin())
        {
            temp3 = (*it).first;
            temp4 = (*it).second;
            diff += temp3 - s[i];
            probs.push_back(temp3);
            temp3++;
            itvls.erase(it);
            if (temp4 - temp3 >= 0)
            {
                itvls[temp3] = temp4; //adds new interval
            }
        }
        //what happens if end interval?
        else if (it == itvls.end())
        {
            --it;
            temp3 = (*it).first;
            temp4 = (*it).second;
            diff += s[i] - temp4;
            probs.push_back(temp4);
            temp4--;
            itvls.erase(it);
            if (temp4 - temp3 >= 0)
            {
                itvls[temp3] = temp4; //adds new interval
            }
        }
        else
        {
            auto it2 = it;
            it2--;
            temp3 = (*it2).first;
            temp4 = (*it2).second;
            if (temp4 >= s[i]) //inside a problem range
            {
                diff += 0;
                itvls.erase(it2);
                probs.push_back(s[i]);
                if (s[i] - 1 - temp3 >= 0)
                {
                    itvls[temp3] = s[i] - 1; //adds new interval
                }
                if (temp4 - (s[i] + 1) >= 0)
                {
                    itvls[s[i] + 1] = temp4;
                }
            }
            else
            { //outside a problem range;
                //left is closer
                ll left = (*it2).second;
                ll right = (*it).first;
                if (s[i] - left <= right - s[i])
                {
                    diff += s[i] - (*it2).second;
                    temp3 = (*it2).first;
                    temp4 = (*it2).second;
                    itvls.erase(it2);
                    probs.push_back(left);
                    temp4--;
                    if (temp4 - temp3 >= 0)
                    {
                        itvls[temp3] = temp4; //adds new interval
                    }
                }
                //right is closer
                else
                {
                    diff += (*it).first - s[i];
                    temp3 = (*it).first;
                    temp4 = (*it).second;
                    itvls.erase(it);
                    probs.push_back(right);
                    temp3++;
                    if (temp4 - temp3 >= 0)
                    {
                        itvls[temp3] = temp4; //adds new interval
                    }
                }
            }
        }
    }
    cout << "Case #" << casenum << ": ";
    for (auto i : probs)
    {
        cout << i;
        cout << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}