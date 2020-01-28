// Question Link ---> https://leetcode.com/problems/unique-number-of-occurrences/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> uniqs;
        unordered_map<int, int> occ;
        for (auto i : arr) occ[i]++;
        for (auto m : occ) {
            if (!uniqs.count(m.second)) {
                uniqs.insert(m.second);
            } else {
                return false;
            }
        }
        return true;
    }
};