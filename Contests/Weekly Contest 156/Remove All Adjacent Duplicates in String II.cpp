// Question Link ---> https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
class Solution {
public:
	string removeDuplicates(string s, int k) {
        if (k > s.size()) {
            return s;
        }
		string res = "";
		int oldSize = s.size();
		int newSize = remover(s, k);
		while (oldSize != newSize) {
			oldSize = newSize;
			newSize = remover(s, k);
		}
		return s;
	}

	int remover(string &s, int k) {
		string res = "";
		for (int i = 0; i < s.size(); i++) {
			int j = i + 1;
			bool key = false;
			for (int till = 1; till < k; j++, till++) {
				if (s[i] != s[j]) {
					res += s[i];
					key = true;
					break;
				}
			}
			if (!key) i = j - 1;
		}
		s = res;
		return res.size();
	}
};