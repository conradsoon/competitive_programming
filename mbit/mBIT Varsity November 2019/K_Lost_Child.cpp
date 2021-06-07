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
struct pos
{
    ld x;
    ld y;
};

pos add_pos(const pos &a, const pos &b)
{
    return {a.x + b.x, a.y + b.y};
}
pos subtract_pos(const pos &a, const pos &b)
{
    return {a.x - b.x, a.y - b.y};
}
pos scalar_multi_pos(const pos &a, ld lda)
{
    return {lda * a.x, lda * a.y};
}
pos interpolate(pos start_pos, pos end_pos, ld start_time, ld end_time, ld curr_time)
{
    pos dir = subtract_pos(end_pos, start_pos);
    ld lda = (curr_time - start_time) / (end_time - start_time);
    return add_pos(start_pos, scalar_multi_pos(dir, lda));
}
ld dist(pos a, pos b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
ld shortest_dist(pos p_s, pos p_e, pos q_s, pos q_e, ld t_s, ld t_e)
{
    //https://math.stackexchange.com/questions/1775476/shortest-distance-between-two-objects-moving-along-two-lines
    pos v_p = scalar_multi_pos(subtract_pos(p_e, p_s), 1 / (t_e - t_s));
    pos v_q = scalar_multi_pos(subtract_pos(q_e, q_s), 1 / (t_e - t_s));
    ld a = q_s.x - p_s.x;
    ld b = v_q.x - v_p.x;
    ld c = q_s.y - p_s.y;
    ld d = v_q.y - v_p.y;
    if (b == 0 && d == 0)
    {
        return sqrt(pow(a, 2) + pow(c, 2));
    }
    else
    {
        ld t = (-1) * (a * b + c * d) / (b * b + d * d);
        ld result;
        if (t + t_s < t_s || t + t_s > t_e)
        {
            result = (min(dist(p_s, q_s), dist(p_e, q_e)));
        }
        else
        {
            result = sqrt(pow(a + b * t, 2) + pow(c + d * t, 2));
        }
        return result;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    ld g, a;
    cin >> n >> m >> g >> a;
    vector<pos> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    vector<pos> q(m);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].x >> q[i].y;
    }
    vector<ld> p_t(n, 0);
    for (int i = 1; i < n; i++)
    {
        p_t[i] = p_t[i - 1] + dist(p[i], p[i - 1]) / g;
    }
    vector<ld> q_t(m, 0);
    for (int i = 1; i < m; i++)
    {
        q_t[i] = q_t[i - 1] + dist(q[i], q[i - 1]) / a;
    }
    int it_p = 0;
    int it_q = 0;
    pos g_pos = p[0];
    pos a_pos = q[0];
    ld t_p = 0;
    ld t_q = 0;
    vector<ld> e;
    vector<pos> p_e;
    vector<pos> q_e;
    bool p_flag = true;
    bool q_flag = true;
    while (p_flag || q_flag)
    {
        //if end position, remember to freeze the position
        if (p_flag)
        {
            t_p = p_t[it_p];
        }
        if (q_flag)
        {
            t_q = q_t[it_q];
        }
        if (t_p < t_q)
        {
            g_pos = p[it_p];
            a_pos = interpolate(q[it_q - 1], q[it_q], q_t[it_q - 1], q_t[it_q], t_p);
            e.push_back(t_p);
            it_p++;
            if (it_p == n)
            {
                p_flag = false;
                it_p--;
                t_p = t_q;
            }
        }
        else if (t_q < t_p)
        {
            g_pos = interpolate(p[it_p - 1], p[it_p], p_t[it_p - 1], p_t[it_p], t_q);
            a_pos = q[it_q];
            e.push_back(t_q);
            it_q++;
            if (it_q == m)
            {
                q_flag = false;
                it_q--;
                t_q = t_p;
            }
        }
        else if (t_p == t_q)
        {
            g_pos = p[it_p];
            a_pos = q[it_q];
            e.push_back(t_p);
            it_p++;
            it_q++;
            if (it_p == n)
            {
                p_flag = false;
                it_p--;
                t_p = t_q;
            }
            if (it_q == m)
            {
                q_flag = false;
                it_q--;
                t_q = t_p;
            }
        }
        p_e.push_back(g_pos);
        q_e.push_back(a_pos);
    }
    ld minimum = 1e20;
    for (int i = 1; i < e.size(); i++)
    {
        minimum = min(minimum, shortest_dist(p_e[i - 1], p_e[i], q_e[i - 1], q_e[i], e[i - 1], e[i]));
    }
    cout << (long long)(minimum + 0.5);
    return 0;
}