// Question Link ---> https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return (size == 0 ? 0 : nums[0]);
        }
        if (size == 2) {
            return max(nums[0], nums[1]);
        }
        if (size == 3) {
            return max(nums[0], max(nums[2], nums[1]));
        }
        
        vector<int> nums2 = nums;
        for (int i = 3; i < size; i++) {
            nums2[i] = max((nums2[i] + nums2[i - 2]), nums2[i - 1]);
            nums2[i - 1] = max(nums2[i - 1], nums2[i - 2]);
        }
        
        for (int i = 2; i < size - 1; i++) {
            nums[i] = max((nums[i] + nums[i - 2]), nums[i - 1]);
            nums[i - 1] = max(nums[i - 1], nums[i - 2]);
        }
        
        return max(nums[size - 2], nums2[size - 1]);
    }
};