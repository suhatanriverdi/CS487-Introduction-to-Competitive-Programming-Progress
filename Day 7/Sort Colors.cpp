// Question Link ---> https://leetcode.com/problems/sort-colors/
// Day #7
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return;
        int front = 0, end = nums.size() - 1;
        while (front < nums.size() && nums[front] == 0) front++;
        if (front >= nums.size()) return;
        for (int i = front; i < nums.size(); i++) if (nums[i] == 0) swap(nums[i], nums[front++]);
        while (end > 0 && nums[end] == 2) end--;
        for (int i = front; i < nums.size() && i < end; i++) {
            if (nums[i] == 2) {
                swap(nums[i], nums[end--]);
                while (end > 0 && nums[end] == 2) end--;
            }
        }
    }
};