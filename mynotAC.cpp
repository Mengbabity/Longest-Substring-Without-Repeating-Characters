#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		if (n == 0)
			return 0;
		int res = 1;
		int mid = 0;
		map<char, int> m;
		int i = 0;

		while (i<n)
		{
			m[s[i]]++;
			if (m[s[i]]>1)
			{
				int tmp = 0;
				for (auto e : m)
					tmp += e.second;
				res = max(tmp - 1, res);
				m.clear();
				m[s[i]]++;
			}
			i++;
		}

		for (auto e : m)
			mid += e.second;

		res = max(mid, res);

		return res;

	}
};

void main()
{
	Solution s;
	s.lengthOfLongestSubstring("dvdf");
}
