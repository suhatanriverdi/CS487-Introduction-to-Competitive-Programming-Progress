// Question Link ---> https://leetcode.com/problems/get-equal-substrings-within-budget/
class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int size = s.size();
		vector<int> diff(s.length());
		for (int i = 0; i < size; i++) {
			diff[i] = abs(s[i] - t[i]);
		}
		int end = 0, start = 0, sum = 0;
		while (end < size) {
			sum += diff[end++];
			if (sum > maxCost) {
				sum -= diff[start++];
			}
		}
		return end - start;
	}
};