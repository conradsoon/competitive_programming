#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<char>; // char faster
using vvb = vector<vector<char>>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Bfn
{ // Blowfishnum
public:
	Bfn *p;	 // parent
	Bfn *lc; // leftchild
	Bfn *rc; // rightchild
	int v;	 //-1 indicates is Bfn, containing two smaller, non -1 indicates is literal value
	Bfn()
	{
		v = -1;
		p = nullptr;
		lc = nullptr;
		rc = nullptr;
	}
	Bfn(Bfn *lc, Bfn *rc) : lc(lc), rc(rc)
	{
		p = nullptr;
		v = -1;
	}
	Bfn(int v) : v(v)
	{
		p = nullptr;
		lc = nullptr;
		rc = nullptr;
	}
	Bfn *initChildren()
	{
		lc = new Bfn();
		lc->p = this;
		rc = new Bfn();
		rc->p = this;
		return lc;
	}
	void explode()
	{
		int lv = lc->v;
		assert(lv != -1);
		int rv = rc->v;
		assert(rv != -1);
		Bfn *lidx = this;
		while (lidx->p != nullptr && lidx->p->lc == lidx)
		{
			lidx = lidx->p;
		}
		if (lidx->p != nullptr)
		{
			lidx = lidx->p->lc;
			while (lidx->rc != nullptr)
			{
				lidx = lidx->rc;
			}
			lidx->v += lv;
		}
		Bfn *ridx = this;
		while (ridx->p != nullptr && ridx->p->rc == ridx)
		{
			ridx = ridx->p;
		}
		if (ridx->p != nullptr)
		{
			ridx = ridx->p->rc;
			while (ridx->lc != nullptr)
			{
				ridx = ridx->lc;
			}
			ridx->v += rv;
		}
		delete lc;
		delete rc;
		lc = nullptr;
		rc = nullptr;
		v = 0;
	}
	void split()
	{
		int lv = v / 2;
		int rv = (v + 1) / 2;
		v = -1;
		lc = new Bfn(lv);
		lc->p = this;
		rc = new Bfn(rv);
		rc->p = this;
	}
	void check_split(int d, bool &flag)
	{
		if (v >= 10)
		{
			cout << "SPLITTING:\n";
			cout << "d: " + to_string(d) + " " + to_str() << "\n";
			flag = true;
			this->split();
			return;
		}
		if (flag)
		{
			return;
		}
		if (lc != nullptr)
		{
			lc->check_split(d + 1, flag);
		}
		if (flag)
		{
			return;
		}
		if (rc != nullptr)
		{
			rc->check_split(d + 1, flag);
		}
	}
	void check_exp(int d, bool &flag)
	{
		if (v == -1 && d == 4)
		{
			cout << "EXPLODING:\n";
			cout << "d: " + to_string(d) + " " + to_str() << "\n";
			flag = true;
			this->explode();
			return;
		}
		if (flag)
		{
			return;
		}
		if (lc != nullptr)
		{
			lc->check_exp(d + 1, flag);
		}
		if (flag)
		{
			return;
		}
		if (rc != nullptr)
		{
			rc->check_exp(d + 1, flag);
		}
	}
	void check_fix()
	{
		while (true)
		{
			bool flagexp = false;
			bool flagsplit = false;
			this->check_exp(0, flagexp);
			cout << this->to_str() << "\n";
			if (flagexp)
			{
				continue;
			}
			this->check_split(0, flagsplit);
			cout << this->to_str() << "\n";
			if (!flagexp && !flagsplit)
			{
				break;
			}
		}
	}
	string to_str()
	{
		if (v != -1)
		{
			assert(lc == nullptr);
			assert(rc == nullptr);
			return to_string(v);
		}
		return "[" + lc->to_str() + "," + rc->to_str() + "]";
	}
	ll mag()
	{
		if (v != -1)
		{
			return v;
		}
		return 3 * lc->mag() + 2 * rc->mag();
	}
};

Bfn *parseString(string s)
{
	int n = s.size();
	Bfn *b = new Bfn();
	Bfn *idx = b;
	string valstr = "";
	for (int i = 0; i < n; i++)
	{
		char c = s[i];
		if (c == '[')
		{
			idx = idx->initChildren();
		}
		else if (c == ',')
		{
			if (idx->lc == nullptr && idx->rc == nullptr)
			{
				idx->v = stoi(valstr, nullptr, 10);
				valstr = "";
			}
			idx = idx->p;
			idx = idx->rc;
		}
		else if (c == ']')
		{
			if (idx->lc == nullptr && idx->rc == nullptr)
			{
				idx->v = stoi(valstr, nullptr, 10);
				valstr = "";
			}
			idx = idx->p;
		}
		else
		{
			valstr.push_back(c);
		}
	}
	return b;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("outputb.txt", "w", stdout);
	vector<string> strs;
	string temp;
	while (cin >> temp)
	{
		strs.pb(temp);
	}
	int n = sz(strs);
	ll maxmag = -INFLL;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			Bfn *b = new Bfn(parseString(strs[i]), parseString(strs[j]));
			b->lc->p = b;
			b->rc->p = b;
			b->check_fix();
			setmax(maxmag, b->mag());
		}
	}
	cout << maxmag << "\n";
	return 1;
}
