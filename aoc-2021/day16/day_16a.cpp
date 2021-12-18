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

class Packet
{
private:
public:
	string *bsr;
	vector<Packet *> subPackets;
	Packet *parentPacket;
	int sidx;
	int eidx;
	int v;
	int ptid;
	int ltid = -1;
	int tlib = -1;
	int nsp = -1;
	ll val = -1;
	Packet(string *bsr, int sidx) : bsr(bsr), sidx(sidx)
	{
	}
	int process()
	{
		int idx = sidx;
		if (idx == 219)
		{
			cout << "ping!";
		}
		cout << idx << endl;
		v = stoi(bsr->substr(idx, 3), nullptr, 2);
		idx += 3;
		ptid = stoi(bsr->substr(idx, 3), nullptr, 2);
		idx += 3;
		if (ptid != 4)
		{
			ltid = stoi(bsr->substr(idx, 1), nullptr, 2);
			idx += 1;
			if (ltid == 0)
			{
				tlib = stoi(bsr->substr(idx, 15), nullptr, 2);
				idx += 15;
				int b = 0;
				while (b < tlib)
				{
					Packet *npkt = new Packet(bsr, idx);
					npkt->parentPacket = this;
					int nidx = npkt->process();
					b += nidx - idx;
					idx = nidx;
					subPackets.pb(npkt);
				}
			}
			else
			{
				nsp = stoi(bsr->substr(idx, 11), nullptr, 2);
				idx += 11;
				int c = 0;
				while (c < nsp)
				{
					Packet *npkt = new Packet(bsr, idx);
					npkt->parentPacket = this;
					idx = npkt->process();
					subPackets.pb(npkt);
					c++;
				}
			}
		}
		else
		{
			string valstr = "";
			string temp;
			while (true)
			{
				temp = bsr->substr(idx, 5);
				idx += 5;
				valstr.append(temp.substr(1, 4));
				if (temp[0] == '0')
				{
					break;
				}
			}
			val = stoll(valstr, nullptr, 2);
		}
		eidx = idx;
		return idx;
	};
	ll sum_of_versions()
	{
		ll ans = 0;
		ans += v;
		for (auto ptsp : subPackets)
		{
			ans += ptsp->sum_of_versions();
		}
		return ans;
	}
	ll operate()
	{
		switch (ptid)
		{
		case 0:
		{
			ll ans = 0;
			for (auto ptsp : subPackets)
			{
				ans += ptsp->operate();
			}
			return ans;
		}
		case 1:
		{
			ll ans = 1;
			for (auto ptsp : subPackets)
			{
				ans *= ptsp->operate();
			}
			return ans;
		}
		case 2:
		{
			ll ans = INFLL;
			for (auto ptsp : subPackets)
			{
				ans = min(ans, ptsp->operate());
			}
			return ans;
		}
		case 3:
		{
			ll ans = -INFLL;
			for (auto ptsp : subPackets)
			{
				ans = max(ans, ptsp->operate());
			}
			return ans;
		}
		case 4:
		{
			return val;
		}
		case 5:
		{
			return subPackets[0]->operate() > subPackets[1]->operate();
		}
		case 6:
		{
			return subPackets[0]->operate() < subPackets[1]->operate();
		}
		case 7:
		{
			return subPackets[0]->operate() == subPackets[1]->operate();
		}
		default:
		{
			assert(false);
		}
		}
	}
};

string hex2bin(char h)
{
	switch (h)
	{
	case '0':
		return "0000";
		break;
	case '1':
		return "0001";
		break;
	case '2':
		return "0010";
		break;
	case '3':
		return "0011";
		break;
	case '4':
		return "0100";
		break;
	case '5':
		return "0101";
		break;
	case '6':
		return "0110";
		break;
	case '7':
		return "0111";
		break;
	case '8':
		return "1000";
		break;
	case '9':
		return "1001";
		break;
	case 'A':
		return "1010";
		break;
	case 'B':
		return "1011";
		break;
	case 'C':
		return "1100";
		break;
	case 'D':
		return "1101";
		break;
	case 'E':
		return "1110";
		break;
	case 'F':
		return "1111";
		break;
	default:
		return "-1";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	// freopen("output_a.txt", "w", stdout);
	string hexinput = "";
	cin >> hexinput;
	string *bsr = new string();
	for (auto c : hexinput)
	{
		bsr->append(hex2bin(c));
	}
	cout << *bsr << endl;
	auto basePacket = new Packet(bsr, 0);
	basePacket->process();
	cout << basePacket->sum_of_versions() << endl;
	cout << basePacket->operate() << endl;
	return 1;
}
