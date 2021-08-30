#include <bits/stdc++.h>
#include <sstream>
#include <string>
//Add a comparison function
using namespace std;
bool ses(string a, string b){
        if((a == "upper" && b == "middle") || (a == "middle" && b == "lower" || (a == "upper" && b == "lower"))){
            return true;
        }
        else{
            return false;
        }
}

struct Person{
    string name;
    vector<string> token_class;

    Person(string name, string full_class){
        this->name = name;
        istringstream split(full_class);
        for(string cls; getline(split, cls, '-'); token_class.push_back(cls));
    }

    friend bool operator<(Person a, Person b){
        int na = a.token_class.size() - 1;
        int nb = b.token_class.size() - 1;
        while( (na>=0||nb>=0) && ((na<0?"middle":a.token_class[na]) == (nb<0?"middle":b.token_class[nb])) ){
            na--; nb--;
        }

        if((na<0?"middle":a.token_class[na]) == (nb<0?"middle":b.token_class[nb])){
            return a.name < b.name;
        }
        
        else{
            return ses((na<0?"middle":a.token_class[na]),(nb<0?"middle":b.token_class[nb]));
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        vector<Person> society;
        while(k--){
            string name, fullclass, trash;
            cin >> name >> fullclass >> trash;
            name.pop_back();
            society.push_back(Person(name, fullclass));
        }
        sort(society.begin(),society.end());
        for(const auto peep : society){
            cout << peep.name << "\n";
        }
        cout << "==============================\n";
    }
    return 0;
}