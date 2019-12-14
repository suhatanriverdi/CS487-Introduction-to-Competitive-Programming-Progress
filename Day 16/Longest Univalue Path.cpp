// Question Link ---> https://leetcode.com/problems/longest-univalue-path/
// Day #16
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root || (root && !root->right && !root->left)) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxPathSoFar = 0;
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            maxPathSoFar = max(sumLeftRight(cur), maxPathSoFar);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return maxPathSoFar;
    }
    
    int sumLeftRight(TreeNode *node) {
        return maxDepth(node->left, node->val) + maxDepth(node->right, node->val);
    }
    
    int maxDepth(TreeNode *cur, int &lastVal) {
        if (!cur || lastVal != cur->val) return 0;
        return 1 + max(maxDepth(cur->left, cur->val), maxDepth(cur->right, cur->val));
    }
};