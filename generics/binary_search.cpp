// https://codeforces.com/blog/entry/9901
bool search(int x[], int n, int k)
{
	int p = 0;
	for (int a = n; a >= 1; a /= 2)
	{
		while (p + a < n && x[p + a] <= k)
			p += a;
	}
	return x[p] == k;
}