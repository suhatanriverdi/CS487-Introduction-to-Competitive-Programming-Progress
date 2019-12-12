// Question Link ---> https://leetcode.com/contest/weekly-contest-138/problems/distant-barcodes/
// Day #7
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map> // Map sorts according to keys
#include <set> // Set sorts according to values which we need here!
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if (barcodes.size() < 3) return barcodes;
		unordered_map<int, int> m;
		for (auto &i : barcodes) m[i]++;
		set<pair<int, int>> s;
		for (auto it = m.begin(); it != m.end(); it++) s.insert({it->second, it->first});
		vector<int> res(barcodes.size());
		int i = 0;
		for (auto it = s.rbegin(); it != s.rend(); it++) {
			for (int left = 0; left<it->first; left++) {
				if (i >= res.size()) i = lastSpace(res);
				res[i] = it->second;
				i += 2;
			}
		}
		return res;
    }
    
    int lastSpace(vector<int> &vec) {
    	for (int i = 0; i < vec.size(); i++) if (vec[i] == 0) return i;
		return 0;
	}
};

int main(void) {
	vector<int> vec = {7, 7, 7, 8, 5, 7, 5, 5, 5, 8};
	for (auto &i : vec) cout << i << " "; 
	cout << endl;
    Solution obj;
    vec = obj.rearrangeBarcodes(vec);
    for (auto &i : vec) cout << i << " "; 
    return 0;
}
