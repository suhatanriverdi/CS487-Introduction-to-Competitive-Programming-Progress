// Question Link ---> https://leetcode.com/problems/valid-anagram/
// Day #6
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> ms, mt;
		for (auto c : s) ms[c]++;
		for (auto c : t) mt[c]++;
		return (ms == mt);
	}
};

int main(void) {
	string a = "rat", b = "car";
	Solution obj;
	cout << "Output: " << obj.isAnagram(a, b);
	return 0;
}