// Question Link ---> https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rotPointIndex = -1, size = nums.size();
        if (size == 0) {
            return -1;
        }
        if (size == 1) {
            return (nums[0] == target ? 0 : -1);
        }
        for (int i = 0; i + 1 < size; i++) {
            if (nums[i] > nums[i + 1]) {
                rotPointIndex = i;
                break;
            }
        }
        cout << "rot: " << rotPointIndex << endl;
        if (rotPointIndex == -1) {
            return binarySearch(nums, 0, size - 1, target);
        }
        //         0 1 2 3 4 5 6 
        // nums = [4,5,6,7,0,1,2]
        // We know rotation Point index "3"
        int res;
        if (target >= nums[0] && target <= nums[rotPointIndex]) {
            if (target == nums[0]) {
                return 0;
            }
            if (target == nums[rotPointIndex]) {
                return rotPointIndex;
            }
            res = binarySearch(nums, 0, rotPointIndex, target);
        } 
        else {
            if (target == nums[rotPointIndex + 1]) {
                return rotPointIndex + 1;
            }
            if (target == nums[size - 1]) {
                return size - 1;
            }
            res = binarySearch(nums, rotPointIndex + 1, size - 1, target);
        }
        return res;
    }
    
    int binarySearch(vector<int> &nums, int l, int r, int target) {
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};