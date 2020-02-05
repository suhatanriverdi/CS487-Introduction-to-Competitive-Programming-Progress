// Question Link ---> https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) {
            return (size == 1 ? nums[0] : (size == 0 ? 0 : max(nums[0], nums[1])));
        }
        for (int i = 2; i < nums.size(); i++) {
            nums[i] = max(nums[i - 1], nums[i] + nums[i - 2]);
            nums[i - 1] = max(nums[i - 2], nums[i - 1]);
        }
        return nums[size - 1];
    }
};