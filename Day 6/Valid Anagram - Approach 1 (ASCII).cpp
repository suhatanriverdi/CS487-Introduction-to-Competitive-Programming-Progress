// Question Link ---> https://leetcode.com/problems/valid-anagram/
// Day #6
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		vector<int> freqs(26, 0);
		for (auto c : s) freqs[(c - '0') - '1']++;
		for (auto c : t) freqs[(c - '0') - '1']--;
	 	for (auto i : freqs) if (i != 0) return false;
		return true;
	}
};

int main(void) {
	string a = "anagram", b = "nagaram";
	Solution obj;
	cout << "Output: " << obj.isAnagram(a, b);
	return 0;
}