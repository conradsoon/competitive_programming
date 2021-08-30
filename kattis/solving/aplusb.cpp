#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <complex.h>
#include <unordered_map>
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

//https://cp-algorithms.com/algebra/fft.html
using cd = complex<double>;
const double PI = acos(-1);
//if it doesnt work just set everything to LL;
void fft(vector<cd> &a, bool invert)
{
    ll n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (ll i = 0; 2 * i < n; i++)
    {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (ll i = 0; 2 * i < n; i++)
    {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert)
        {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}
vector<ll> multiply(vector<ll> const &a, vector<ll> const &b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> no(n);
    unordered_map<ll, ll> coeff;
    ll min_no = 50001;
    ll max_no = -50001;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        coeff[a]++;
        min_no = min(a, min_no);
        max_no = max(a, max_no);
    }
    vector<ll> gen_func(max_no + (-min_no) + 1, 0);
    for (auto it : coeff)
    {
        gen_func[it.first - min_no] = it.second;
    }
    vector<ll> fast_pol_mul = multiply(gen_func, gen_func);
    ll offset = (min_no)*2;
    for (auto it : coeff)
    {
        fast_pol_mul[it.first * 2 - offset] -= it.second;
    }
    ll sum = 0;
    for (auto it : coeff)
    {
        if (it.first - offset >= 0)
        {
            sum += fast_pol_mul[it.first - offset]*it.second;
        }
    }
    if (coeff.count(0) == 1)
    {
        sum -= (ll)2 * coeff[0] * (n - 1);
    }
    cout << sum;
    return 0;
}