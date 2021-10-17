//https : //cp-algorithms.com/data_structures/disjoint_set_union.html
//vector<int> parent;
//vector<int> size;
void make_set(int v)
{
	parent[v] = v;
	sze[v] = 1;
}
int find_set(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		if (sze[a] < sze[b])
			swap(a, b);
		parent[b] = a;
		sze[a] += sze[b];
	}
}