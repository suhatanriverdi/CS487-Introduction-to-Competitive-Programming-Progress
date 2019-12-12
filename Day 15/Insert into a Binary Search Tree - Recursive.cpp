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
        return insert(root, val);
    }
    
    TreeNode* insert(TreeNode* current, int n) {
        if (current == NULL) return new TreeNode(n);
        if (n > current->val) current->right = insert(current->right, n);
        if (n < current->val) current->left = insert(current->left, n);
        return current;
    }
};