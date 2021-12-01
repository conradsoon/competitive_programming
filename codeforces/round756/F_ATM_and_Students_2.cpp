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
using vb = vector<char>; //char faster
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
// C++ Program to compute the
// longest subarray with
// sum greater than equal to 0.
#include <bits/stdc++.h>
using namespace std;

// Function for the searching the
// starting index of the subarray
int search(int *searchspace, int s, int e, int key)
{
	// -1 signifies that no
	// starting point of the subarray
	// is not found with sum greater
	// than equal to 0.
	int ans = -1;

	// Binary search
	while (s <= e)
	{
		int mid = (s + e) / 2;

		if (searchspace[mid] - key >= 0)
		{
			ans = mid;
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}

	return ans;
}

// Function to return the longest subarray
pii longestSubarray(ll a[], ll n, ll s)
{
	// Array for the suffix sum
	// of the above the array.
	ll SuffixSum[n + 1];
	SuffixSum[n] = s;

	for (int i = n - 1; i >= 0; --i)
	{
		SuffixSum[i] = SuffixSum[i + 1] + a[i];
	}

	int ans = 0;

	// Search Space for potential starting
	// points of the subarray.
	// It will store the suffix sum
	// till i'th index in increasing order.
	int searchspace[n];

	// It will store the indexes
	// till which the suffix sum
	// is present in search space.
	int index[n];
	int i_m = -1;
	int j = 0;

	for (int i = 0; i < n; ++i)
	{

		// add the element to the search space if the j=0
		// or if the topmost element is lesser
		// than present suffix sum.
		if (j == 0 or SuffixSum[i] > searchspace[j - 1])
		{
			searchspace[j] = SuffixSum[i];
			index[j] = i;
			j++;
		}

		int idx = search(searchspace, 0, j - 1, SuffixSum[i + 1]);

		// Only when idx is not -1 an subarray is
		// possible with ending index at i.
		if (idx != -1)
		{
			if (i - index[idx] + 1 > ans)
			{
				ans = i - index[idx] + 1;
				i_m = i;
			}
		}
		//ans = max(ans, i - index[idx] + 1);
	}

	return {ans, i_m};
}

void solve(int tc)
{
	ll n, s;
	cin >> n >> s;
	ll a[n];
	forn(i, 0, n)
	{
		cin >> a[i];
	}
	pii an = longestSubarray(a, n, s);
	if (an.se == -1)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << an.se - an.fi + 1 + 1 << " " << an.se + 1 << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}