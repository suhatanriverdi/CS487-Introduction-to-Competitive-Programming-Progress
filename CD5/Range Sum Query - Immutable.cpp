// Question Link ---> https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
    vector<int> accu = {0};
    NumArray(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            accu.push_back(nums[i] + accu.back());
        }
    }
    
    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */