//C++: Close Subsequences (Varsity)
#include <bits/stdc++.h>
using namespace std;
template <int SZ>
struct SegmentTree
{
    int mx[2 * SZ];
    void set(int i, int x)
    {
        int cur = query(i, i);
        if (x > cur)
        {
            update(i, x - cur);
        }
    }
    void update(int i, int x, int l = 0, int r = SZ - 1, int idx = 0)
    {
        if (r < i || l > i)
            return;
        if (l == r)
        {
            mx[idx] += x;
            return;
        }
        int m = (l + r) / 2;
        update(i, x, l, m, 2 * idx + 1);
        update(i, x, m + 1, r, 2 * idx + 2);
        mx[idx] = max(mx[2 * idx + 1], mx[2 * idx + 2]);
    }
    int query(int lo, int hi, int l = 0, int r = SZ - 1, int idx = 0)
    {
        if (r < lo || l > hi)
            return 0;
        if (l >= lo && r <= hi)
            return mx[idx];
        int m = (l + r) / 2;
        return max(query(lo, hi, l, m, 2 * idx + 1), query(lo, hi, m + 1, r, 2 * idx + 2));
    }
};
const int MAXN = 10;
const int MAXK = 5;
SegmentTree<(1 << 17)> seg[MAXK];
int dp[MAXN];
int a[MAXN];
int original[MAXN];
unordered_map<int, int> convert;
int main()
{
    int n, k, m, b;
    cin >> n >> k >> m >> b;
    set<int> compress;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        compress.insert(a[i]), original[i] = a[i];
    int idx = 0;
    for (auto x : compress)
    {
        convert[x] = idx;
        idx++;
    }
    for (int i = 0; i < n; i++)
        a[i] = convert[a[i]];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int mod = 0; mod < m; mod++)
        {
            if (abs(mod - original[i]) % m <= b)
            {
                auto lower = compress.lower_bound(original[i] - k);
                auto upper = prev(compress.upper_bound(original[i] + k));
                dp[i] = max(dp[i], seg[mod].query(max(0, convert[*lower]),
                                                  min(n - 1, convert[*upper])) +
                                       1);
            }
        }
        seg[original[i] % m].set(a[i], dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}