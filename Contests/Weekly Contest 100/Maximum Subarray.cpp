// Question Link ---> https://leetcode.com/problems/maximum-subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > curMax) {
                curMax = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return curMax;
    }
};