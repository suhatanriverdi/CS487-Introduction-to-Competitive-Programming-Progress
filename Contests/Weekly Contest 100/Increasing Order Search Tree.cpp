// Question Link ---> https://leetcode.com/problems/increasing-order-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        vector<int> nums;
        inOrder(root, nums);
        TreeNode *newRoot = new TreeNode(nums[0]);
        TreeNode *walk = newRoot;
        for (int i = 1; i < nums.size(); i++) {
            walk->right = new TreeNode(nums[i]);
            walk = walk->right;
        }
        return newRoot;
    }
    
    void inOrder(TreeNode* cur, vector<int> &nums) {
        if (cur == NULL) return;
        inOrder(cur->left, nums);
        if (cur != NULL) nums.push_back(cur->val);
        inOrder(cur->right, nums);
    }
};