// Question Link ---> https://leetcode.com/problems/path-sum/
// Day #25
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }

        if (!root->left && !root->right && root->val == sum) {
            return true;
        }
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};