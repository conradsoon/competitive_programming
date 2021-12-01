class Solution
{
public:
	vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
	{
		vector<vector<pair<int, int>>> m;
		for (auto mt : meetings)
		{
			m[mt[0]].push_back(mt[2], mt[1]);
			m[mt[1]].push_back(mt[2], mt[0]);
		}
		for (int i = 0; i < n; i++)
		{
			sort(m[i].begin(), m[i].end());
		}
		priority_queue<pair<int, int>> pq;
		vector<char> v(n, 0);
		v[0] = 1;
		pq.insert({0, firstPerson});
		while (!pq.empty())
		{
			int t = pq.front().first;
			int p = pq.front().second;
			pq.pop();
			if (!v[p])
			{
				v[p] = true;
				for (auto itr = lower_bound(m[p].begin(), m[p].end(), {t, -1}); itr != m[p].end(); itr++)
				{
					pq.push({itr.fi, itr.se});
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += v[i];
		}
		return ans;
	}
};