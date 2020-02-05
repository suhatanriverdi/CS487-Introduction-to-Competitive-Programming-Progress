// Question Link ---> https://leetcode.com/problems/bitwise-ors-of-subarrays/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, prev;
        for (auto cur : A) {
            unordered_set<int> temp = {cur};
            for (auto i : prev) {
                temp.insert(i | cur);
            }
            for (auto i : temp) {
                res.insert(i | cur);
            }
            prev = temp;
        }
        return res.size();
    }
};