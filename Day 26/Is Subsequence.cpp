// Question Link ---> https://leetcode.com/problems/is-subsequence/
// Day #26
class Solution {
public:
    bool isSubsequence(string s, string t) {
        while (t.size() > 0 && s.size() > 0) {
            if (s.back() == t.back()) {
                s.pop_back();
            }
            t.pop_back();
        }
        return s.size() == 0;
    }
};