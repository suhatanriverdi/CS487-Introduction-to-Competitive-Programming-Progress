// Question Link ---> https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Day #15
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (val < cur->val) {
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    return root;
                }
                q.push(cur->left);
            }
            
            if (val > cur->val) {
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    return root;
                }
                q.push(cur->right);
            }
        }
        return root;
    }
};