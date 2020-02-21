// Question Link ---> https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (auto &val : A) {
            val = pow(val, 2);
        }
        sort(A.begin(), A.end());
        return A;
    }
};