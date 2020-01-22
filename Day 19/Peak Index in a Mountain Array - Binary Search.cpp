// Question Link ---> https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Day #19
// Binary Search Solution
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1]) {
                return mid;
            }
            if (A[mid] > A[mid - 1]) {
                left = mid + 1;
            }
            if (A[mid] > A[mid + 1]) {
                right = mid - 1;
            }
        }
        return -1;
    }
};