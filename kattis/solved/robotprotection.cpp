#include <bits/stdc++.h>
using namespace std;
pair<int, int> start;
pair<int, int> reference
vector<pair<int,int>> points;

int findstart(){
    int c = 0;
    int minx = points[0].first, miny = points[0].second;
    for(int i = 0; i < points.size(), i++){
        if(points[i].second < miny){
            c = i;
            minx = points[i].first;
            miny = points[i].second;
        }
        else if((points[i].second == miny) && (points[i].first < minx)){
            c = i;
            minx = points[i].first;
            miny = points[i].second;
        }
    }
    return i;
}

float linelength(pair<int,int> a, pair<int,int> b){
    return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

float dot(pair<int,int> a, pair<int,int> b){
    return (a.first*b.first) + (a.second*b.second);
}

bool polarAngle(pair<int,int> a, pair<int,int> b){
    float anga = dot(a, start)/linelength(a, r), angb = dot(b, start);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    while(cin >> n){
        int i = n;
        while(i--){
            int a, b;
            cin >> a >> b;
            points.push_back(make_pair(a,b));
        }

    }
    return 0;
}