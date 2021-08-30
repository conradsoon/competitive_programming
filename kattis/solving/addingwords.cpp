#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string comm;
    string a;
    map<string, int> mem_s2i;
    map<int, string> mem_i2s;
    while(getline(cin, a)){
        istringstream iss(a);
        iss >> comm;
        if(comm == "def"){
            string name;
            int num;
            iss >> name >> num;
            mem_i2s[num] = name;
            mem_s2i[name] = num;
        }
        else if(comm == "calc"){
            string input;
            int sum = 0;
            getline(iss, input);
            string read;
            input.replace(0,1,""); //get rid of leading whitespace
            istringstream inp(input);
            cout << input;
            int sign = 1;
            while(inp >> read){
                if(read == "+"){
                    sign = 1;
                }
                else if(read == "-"){
                    sign = -1;
                }
                else if(read == "="){
                    if(mem_i2s.find(sum) != mem_i2s.end()){
                        cout << " " << mem_i2s[sum] << "\n";
                    }
                    else{
                        cout << " unknown\n";
                    }
                }
                else if(mem_s2i.find(read) == mem_s2i.end()){
                    cout << " unknown\n";
                    break;
                }
                else{ //is a variable
                    sum += sign*mem_s2i[read];
                }
            }
        }
        else if(comm == "clear"){
            mem_s2i.clear();
            mem_i2s.clear();
        }
    }
    return 0;
}