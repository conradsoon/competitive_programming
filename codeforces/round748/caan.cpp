#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
#define fi first
#define se second
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, m, n) for (int i = m, nnnn = (n); i < nnnn; ++i)
#define pb push_back
#define mp make_pair
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t

void debug_out()
{
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 100005;

void solve(bool show)
{
	int n, k, ans = 0;
	cin >> n >> k;
	vector<int> adj[n];
	int dist[n], cnt[n];
	memset(cnt, 0, sizeof cnt);
	memset(dist, 0, sizeof dist);
	forn(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		adj[a - 1].pb(b - 1);
		adj[b - 1].pb(a - 1);
		cnt[a - 1]++, cnt[b - 1]++;
	}
	queue<pair<int, int>> q;
	forn(i, 0, n)
	{
		if (cnt[i] <= 1 && k)
			q.push(mp(i, 1));
	}
	while (!q.empty())
	{
		int v = q.front().fi, g = q.front().se;
		q.pop();
		if (dist[v] == 0)
		{
			dist[v] = g;
			if (g + 1 <= k)
			{
				for (int c : adj[v])
				{
					if (!dist[c])
					{
						cnt[c]--;
						if (cnt[c] <= 1)
						{
							q.push(mp(c, g + 1));
						}
					}
				}
			}
		}
	}
	forn(i, 0, n) if (!dist[i]) ans++;
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(12) << fixed;
	int t;
	cin >> t;
	forn(i, 0, t)
	{
		if (i == 36)
			solve(true);
		else
			solve(false);
	}
}