// Question Link ---> https://leetcode.com/problems/relative-sort-array
// Day #6
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        vector<int> toBeSorted;
        unordered_set<int> s;
        for (auto i2 : arr2) s.insert(i2);
        for (auto i2 : arr2) for (auto i1 : arr1) if (i1 == i2) result.push_back(i2);
		for (auto i1 : arr1) if (!s.count(i1)) toBeSorted.push_back(i1);
		sort(toBeSorted.begin(), toBeSorted.end());
		for (auto ia : toBeSorted) result.push_back(ia);
        return result;
    }
};