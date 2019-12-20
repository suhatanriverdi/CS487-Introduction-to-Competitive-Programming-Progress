// Question Link ---> https://leetcode.com/problems/find-the-duplicate-number/
// Day #19
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums) if (!s.count(num)) s.insert(num); else return num;
        return -1;
    }
};