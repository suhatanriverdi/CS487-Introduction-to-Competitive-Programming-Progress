// Question Link ---> https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Day #19
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > A[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};