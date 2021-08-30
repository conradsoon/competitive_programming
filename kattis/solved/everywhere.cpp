#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n;
    set<string> cities;
    cin >> T;
    while(T--){
    	cin >> n;
	while(n--){
		string input;
		cin >> input;
		cities.insert(input);	
	}
	cout << cities.size() << endl;
	cities.clear();
    }
}
