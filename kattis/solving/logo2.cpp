#include <iostream>
#include <string>
#include <vector>
#include <math.h>

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
#define PI 3.14159265

struct instr
{
    string cmd;
    int arg;
};

struct pos
{
    ld x;
    ld y;
    ld t; //theta
};

ld cosd(ld d)
{
    return cos(d * PI / 180.0);
}
ld sind(ld d)
{
    return sin(d * PI / 180.0);
}
void proc(pos &turtle, const instr &ins)
{
    if (ins.cmd == "fd")
    {
        turtle.x += ins.arg * cosd(turtle.t);
        turtle.y += ins.arg * sind(turtle.t);
    }
    else if (ins.cmd == "bk")
    {
        turtle.x -= ins.arg * cosd(turtle.t);
        turtle.y -= ins.arg * sind(turtle.t);
    }
    else if (ins.cmd == "rt")
    {
        turtle.t = fmod(turtle.t - ins.arg, 360);
        if (turtle.t < 0)
        {
            turtle.t += 360;
        }
    }
    else if (ins.cmd == "lt")
    {
        turtle.t = fmod(turtle.t + ins.arg, 360);
    }
}

instr reverse_instr(const instr &ins)
{
    instr r;
    if (ins.cmd == "fd")
    {
        r.cmd = "bk";
    }
    else if (ins.cmd == "bk")
    {
        r.cmd = "fd";
    }
    else if (ins.cmd == "rt")
    {
        r.cmd = "lt";
    }
    else if (ins.cmd == "lt")
    {
        r.cmd = "rt";
    }
    r.arg = ins.arg;
    return r;
}

int find_missing_link(const instr &ins, const pos &start, const pos &end)
{
    if (ins.cmd == "fd" || ins.cmd == "bk")
    {
        return round(sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2)));
    }
    else if (ins.cmd == "rt" || ins.cmd == "lt")
    {
        ld res = end.t - start.t;
        if (res < 0)
        {
            res += 360;
        }
        return round(res);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<instr> prog(n);
    int ques_pos;
    for (int i = 0; i < n; i++)
    {
        cin >> prog[i].cmd;
        string arg;
        cin >> arg;
        if (arg == "?")
        {
            ques_pos = i;
            prog[i].arg = -1;
        }
        else
        {
            prog[i].arg = stoi(arg);
        }
    }
    pos start = {0, 0, 0};
    for (int i = 0; i < ques_pos; i++)
    {
        proc(start, prog[i]);
    }
    pos end = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        if (prog[i].cmd == "rt" || prog[i].cmd == "lt")
        {
            proc(end, prog[i]);
        }
    }
    for (int i = n - 1; i > ques_pos; i--)
    {
        proc(end, reverse_instr(prog[i]));
    }
    cout << find_missing_link(prog[ques_pos], start, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}