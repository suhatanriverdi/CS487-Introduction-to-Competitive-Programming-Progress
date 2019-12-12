// Question Link ---> https://leetcode.com/problems/range-sum-of-bst/
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        int sum = 0;
        int v = root->val;
        if (v >= L && v <= R) sum += v;
        if (v > L) sum += rangeSumBST(root->left, L, R);
        if (v < R) sum += rangeSumBST(root->right, L, R);
        return sum;
    }
};