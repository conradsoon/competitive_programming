#include <bits/stdc++.h>

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
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
		int n, k;
		cin >> n >> k;
		vector<int> s(n);
		map<int,int> stc;
		for(int i =0; i<n;i++){
			cin >> s[i];
			stc[s[i]]++;
		}
		if(k*2 <n){
			cout << "Case #" << tc << ": NO\n";
			continue;
		}
		bool flag = false;
		for(auto p: stc){
			if(p.second >2){
				cout << "Case #" << tc << ": NO\n";
				flag = true;
				break;
			}
		}
		if(flag){
			continue;
		}
		cout << "Case #" << tc << ": YES\n";
    }
    return 0;
}