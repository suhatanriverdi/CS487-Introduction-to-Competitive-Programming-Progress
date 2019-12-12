// Question Link ---> https://leetcode.com/problems/merge-two-binary-trees/
// Day #14
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        t1->val += t2->val; 
        t1->right = mergeTrees(t1->right, t2->right);
        t1->left = mergeTrees(t1->left, t2->left);
        return t1;
    }
};