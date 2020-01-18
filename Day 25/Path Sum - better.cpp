// Question Link ---> https://leetcode.com/problems/path-sum/
// Day #25
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }

        return helper(root, sum, 0);
    }
    
    bool helper(TreeNode* root, int sum, int pathSum) {
        if (root != NULL) {
            pathSum += root->val;
        }

        if (root && root->left == NULL && root->right == NULL && pathSum == sum) { // Leaf
            return true;
        }

        if (root != NULL) {
            return helper(root->left, sum, pathSum) 
            || helper(root->right, sum, pathSum);
        }
        return false;
    }
};