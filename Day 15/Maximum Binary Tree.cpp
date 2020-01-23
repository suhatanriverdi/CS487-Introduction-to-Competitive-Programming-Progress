// Question Link ---> https://leetcode.com/problems/maximum-binary-tree/
// Day #14
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        vector<bool> taken(nums.size(), false);
        queue<int> orderOfNums;
        queue<TreeNode*> orderOfNodes;
        int curMaxNumIndx = findRightMax(nums, 0, taken);
        TreeNode* maxTree = new TreeNode(nums[curMaxNumIndx]); // Create HEAD
        orderOfNums.push(curMaxNumIndx);
        orderOfNodes.push(maxTree);
        while (!orderOfNums.empty()) {
            int curMaxIdx = orderOfNums.front();
            orderOfNums.pop();
            TreeNode *curNode = orderOfNodes.front();
            orderOfNodes.pop();
            int rightMxIxd = findRightMax(nums, curMaxIdx + 1, taken);
            if (rightMxIxd >= 0) { // Right
                orderOfNums.push(rightMxIxd);
                curNode->right = new TreeNode(nums[rightMxIxd]);
                orderOfNodes.push(curNode->right);
            }
            int leftMxIxd = findLeftMax(nums, curMaxIdx - 1, taken);
            if (leftMxIxd >= 0) { // Left
                orderOfNums.push(leftMxIxd);
                curNode->left = new TreeNode(nums[leftMxIxd]);
                orderOfNodes.push(curNode->left);
            }
        }
        return maxTree;
    }
    
    int findRightMax(vector<int> &nums, int curPos, vector<bool> &taken) {
        int maxNum = INT_MIN, maxNumIndex = -1;
        for (int i = curPos; i < nums.size() && !taken[i]; i++) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxNumIndex = i;
            }
        }
        if (maxNumIndex >= 0) {
            taken[maxNumIndex] = true;
        }
        return maxNumIndex;
    }
    
    int findLeftMax(vector<int> &nums, int curPos, vector<bool> &taken) {
        int maxNum = INT_MIN, maxNumIndex = -1;
        for (int i = curPos; i >= 0 && !taken[i]; i--) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxNumIndex = i;
            }
        }
        if (maxNumIndex >= 0) {
            taken[maxNumIndex] = true;
        }
        return maxNumIndex;
    }
};