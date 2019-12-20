// Question Link ---> https://leetcode.com/problems/binary-search/
// Day #19
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (nums[mid] == target) return mid;
            else {            
                if (target > nums[mid]) L = mid + 1;
                else R = mid - 1;
            }
        }
        return -1;
    }
};