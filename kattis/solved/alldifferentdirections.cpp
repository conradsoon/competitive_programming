#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;
//template ends
#define _USE_MATH_DEFINES
double degreesToRadians(double angle_in_degrees){
	return angle_in_degrees * (M_PI / 180.0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n && n != 0)
    {
        cin.ignore();
        vector<double> x;
        vector<double> y;
        string input;
        while (n--)
        {
            getline(cin, input);
            double currX, currY, angle;
            istringstream inp(input);
            string comm;
            double val;
            inp >> currX >> currY;
            inp >> comm >> angle;
            while (inp >> comm >> val)
            {
                if (comm == "walk")
                {
                    currX += val * cos(degreesToRadians(angle));
                    currY += val * sin(degreesToRadians(angle));
                }
                else if (comm == "turn")
                {
                    angle = fmod((angle + val),360);
                }
            }
            x.push_back(currX);
            y.push_back(currY);
        }
        double avgX = accumulate(x.begin(), x.end(), (double) 0) / x.size();
        double avgY = accumulate(y.begin(), y.end(), (double)0) / y.size();
        double maxDist = 0;
        for (int i = 0; i < x.size(); i++)
        {
            maxDist = max(maxDist, sqrt(pow(x[i] - avgX, 2) + pow(y[i] - avgY, 2)));
        }
        cout << setprecision(10);
        cout << avgX << " " << avgY << " " << maxDist << "\n"; 
    }
    return 0;
}