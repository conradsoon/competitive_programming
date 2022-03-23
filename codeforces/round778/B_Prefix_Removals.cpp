#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using cd = complex<ld>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back // https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back
#define mp make_pair
#define sz(c) size(c)
#define all(c) begin(c), end(c)
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define fora(a, x) for (auto &a : x)
/**
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
**/
template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double EPS = 1e-9;
const long long MOD = 1000000007;
const int MAXN = 200005;
const char nl = '\n';

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// COUT FUNCTIONS

template <class T>
std::ostream &output_iterable_single(std::ostream &stream, T &iterable)
{
	for (auto valIt = iterable.begin(); valIt != iterable.end(); ++valIt)
	{
		auto value = *valIt;
		stream << value;
		if (valIt != --iterable.end())
			stream << ' ';
	}
	return stream;
}

/*
 * Output all values of simple iterable STL containers.
 * std::vector, std::set, std::multiset, std::deque.
 *
 * Usage:
 * std::vector<int> a = {1, 2, 3};
 * std::cout << a << std::endl;
 */

#define OVERLOAD_OUTPUT_SINGLE(container)                                \
	template <typename T>                                                \
	std::ostream &operator<<(std::ostream &stream, container<T> &values) \
	{                                                                    \
		return output_iterable_single(stream, values);                   \
	}

OVERLOAD_OUTPUT_SINGLE(std::vector)
OVERLOAD_OUTPUT_SINGLE(std::set)
OVERLOAD_OUTPUT_SINGLE(std::multiset)
OVERLOAD_OUTPUT_SINGLE(std::deque)

/*
 * Output all values of an array.
 *
 * Usage:
 * std::array<int, 3> a = {1, 2, 3};
 * std::cout << a << std::endl;
 */

template <typename T, size_t SIZE>
std::ostream &operator<<(std::ostream &stream, std::array<T, SIZE> &values)
{
	for (auto valIt = values.begin(); valIt != values.end(); ++valIt)
	{
		auto value = *valIt;
		stream << value;
		if (valIt != values.end() - 1)
			stream << ' ';
	}
	return stream;
}

/* Output all values in a 2-D vector.
 *
 * Usage:
 * std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}};
 * std::cout << a << std::endl;
 */
template <typename T>
std::ostream &operator<<(std::ostream &stream, std::vector<std::vector<T>> &grid)
{
	for (auto rowIt = grid.begin(); rowIt != grid.end(); ++rowIt)
	{
		auto row = *rowIt;
		for (auto valIt = row.begin(); valIt != row.end(); ++valIt)
		{
			auto value = *valIt;
			stream << value;
			if (valIt != row.end() - 1)
				stream << ' ';
		}
		if (rowIt != grid.end() - 1)
			stream << '\n';
	}
	return stream;
}

// END COUT FUNCTIONS

// CIN FUNCTIONS

/*
 * Read all values into a 1-D vector.
 * If the vector has size == 0: Expects an integer first, n, the length of the vector, followed by n integers.
 * If the vector has size > 0:  Expects n integers.
 *
 * Usage:
 * std::vector<int> unsized_vector;
 * std::cin >> unsized_vector;
 * std::vector<int> sized_vector(5, 0);
 * std::cin >> sized_vector;
 */
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &values)
{
	if (values.size() == 0)
	{
		unsigned int N;
		stream >> N;
		values.resize(N);
	}
	for (auto &ele : values)
		stream >> ele;
	return stream;
}

/* Read all values into a 2-D vector.
 * If the vector has size == 0: Expects 2 integers, the length of the vector and the length of each sub-vector, followed by r * c integers.
 * If the vector has size > 0:  Expects r * c integers.
 *
 * Usage:
 * std::vector<std::vector<int>> unsized_vector;
 * std::cin >> unsized_vector;
 * std::vector<std::vector<int>> sized_vector(5, std::vector<int>(5, 0));
 * std::cin >> sized_vector;
 */
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<std::vector<T>> &values)
{
	if (values.size() == 0)
	{
		unsigned int R, C;
		stream >> R >> C;
		values.resize(R);
		for (auto &row : values)
			row.resize(C);
	}
	for (auto &row : values)
		for (auto &val : row)
			stream >> val;
	return stream;
}

/* Read all values into a 1-D array.
 *
 * Usage:
 * std::array<int, 5> sized_array;
 * std::cin >> sized_array;
 */
template <typename T, size_t SIZE>
std::istream &operator>>(std::istream &stream, std::array<T, SIZE> &array)
{
	for (auto &val : array)
		stream >> val;
	return stream;
}

// END CIN FUNCTIONS

#define FAST_IO                            \
	std::ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                         \
	cout.tie(NULL)
#define yn(flag) ((flag) ? "YES" : "NO")
#define sgn(x) (((x) > 0) ? 1 : (((x) < 0) ? -1 : 0))

void solve(int tc)
{
	string s;
	cin >> s;
	vvi d(26);
	int n = s.size();
	forn(i, 0, n)
	{
		d[s[i] - 'a'].pb(i);
	}
	forn(i, 0, n)
	{
		if (d[s[i] - 'a'].back() == i)
		{
			cout << string(s.begin() + i, s.end()) << "\n";
			return;
		}
	}
}

int main()
{
	FAST_IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve(i);
	return 0;
}