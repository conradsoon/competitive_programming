
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
const int MOD = 1000000007;
const int NX = 210001;
const int MX = 210001;

struct mi
{
    ll v;
    explicit operator ll() const { return v; }
    mi() { v = 0; }
    mi(ll _v)
    {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0)
            v += MOD;
    }
    friend bool operator==(const mi &a, const mi &b)
    {
        return a.v == b.v;
    }
    friend bool operator!=(const mi &a, const mi &b)
    {
        return !(a == b);
    }
    friend bool operator<(const mi &a, const mi &b)
    {
        return a.v < b.v;
    }

    mi &operator+=(const mi &m)
    {
        if ((v += m.v) >= MOD)
            v -= MOD;
        return *this;
    }
    mi &operator-=(const mi &m)
    {
        if ((v -= m.v) < 0)
            v += MOD;
        return *this;
    }
    mi &operator*=(const mi &m)
    {
        v = v * m.v % MOD;
        return *this;
    }
    mi &operator/=(const mi &m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p)
    {
        mi ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1)
                ans *= a;
        return ans;
    }
    friend mi inv(const mi &a)
    {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }

    mi operator-() const { return mi(-v); }
    mi &operator++() { return *this += 1; }
    mi &operator--() { return *this -= 1; }
    mi operator++(int)
    {
        mi temp;
        temp.v = v++;
        return temp;
    }
    mi operator--(int)
    {
        mi temp;
        temp.v = v--;
        return temp;
    }
    friend mi operator+(mi a, const mi &b) { return a += b; }
    friend mi operator-(mi a, const mi &b) { return a -= b; }
    friend mi operator*(mi a, const mi &b) { return a *= b; }
    friend mi operator/(mi a, const mi &b) { return a /= b; }
    friend ostream &operator<<(ostream &os, const mi &m)
    {
        os << m.v;
        return os;
    }
    friend istream &operator>>(istream &is, mi &m)
    {
        ll x;
        is >> x;
        m.v = x;
        return is;
    }
};

typedef vector<mi> vmi;
typedef pair<mi, mi> pmi;
typedef vector<pmi> vpmi;

mi facs[MX];
mi facInvs[MX];

mi choose(mi _a, mi _b)
{
    ll a = (ll)_a, b = (ll)_b;
    if (b > a)
        return 0;
    if (a < 0)
        return 0;
    if (b < 0)
        return 0;
    mi cur = facs[a];
    cur = cur * facInvs[b];
    cur = cur * facInvs[a - b];
    return cur;
}

void initFacs()
{
    facs[0] = 1;
    //FOR(i, 1, MX)
    for (int i = 1; i < MX; i++)
    {
        facs[i] = (facs[i - 1] * i);
    }
    facInvs[MX - 1] = inv(facs[MX - 1]);
    for (int i = MX - 1 - 1; i >= 0; i--)
    //F0Rd(i, MX - 1)
    {
        facInvs[i] = facInvs[i + 1] * (i + 1);
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    initFacs();
    mi dp[k + 1][2];
    dp[0][1] = 1;
    mi even, odd;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            odd += choose(n, i);
        }
        else
        {

            even += choose(n, i);
        }
    }
    if (n % 2)
    {
        for (int i = 1; i <= k; i++) //less than, greater than or equals to
        {
            dp[i][0] += dp[i - 1][0];
            dp[i][0] += dp[i - 1][0] * even;
            dp[i][0] += dp[i - 1][0] * odd;
            dp[i][0] += dp[i - 1][1] * odd;
            dp[i][1] += dp[i - 1][1];
            dp[i][1] += dp[i - 1][1] * even;
        }
    }
    else
    {
        for (int i = 1; i <= k; i++) //less than, greater than or equals to
        {
            dp[i][0] += dp[i - 1][0] * even;
            dp[i][0] += dp[i - 1][0] * odd;
            dp[i][0] += dp[i - 1][1] * odd;
            dp[i][1] += dp[i - 1][0];
            dp[i][1] += dp[i - 1][1];
            dp[i][1] += dp[i - 1][1] * even;
        }
    }
    cout << dp[k][1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}