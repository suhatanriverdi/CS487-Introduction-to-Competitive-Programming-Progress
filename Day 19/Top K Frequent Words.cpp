// Question Link ---> https://leetcode.com/problems/top-k-frequent-words/
// Day #19
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res;
		priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> pq;
		unordered_map<string, int> m; // {string, frequency}
		for (auto word : words) m[word]++;
		for (auto pair : m) pq.push({ pair.second, pair.first });
		while (!pq.empty() && k--) { res.push_back(pq.top().second); pq.pop(); }
		return res;
	}
private:
	struct Comp {
		bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
			if (a.first != b.first) return a.first < b.first; // If different freqs then return greater
			if (a.second.compare(b.second) < 0) return false;
			return true;
		}
	};
};