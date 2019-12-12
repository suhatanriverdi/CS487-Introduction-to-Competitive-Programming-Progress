// Question Link ---> https://leetcode.com/problems/intersection-of-two-arrays
// Day #6
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for (auto i : nums1) s.insert(i);
        nums1.clear();
        for (auto i : nums2) if (s.count(i)) { nums1.push_back(i); s.erase(i); }
        return nums1;
    }
};