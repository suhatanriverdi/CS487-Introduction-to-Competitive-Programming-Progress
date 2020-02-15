// Question Link ---> https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
    int maxProduct(TreeNode* root) {
        long long int maxProduct = LLONG_MIN;
        unordered_map<TreeNode*, int> subtreeSum;
        traverseTree(root, subtreeSum);
        splitTree(root, subtreeSum, maxProduct, root);
        return maxProduct % (int)(1e9 + 7);
    }
    
    void splitTree(TreeNode *cur, unordered_map<TreeNode*, int> &subSum, long long int &maxProduct, TreeNode *root) {
        if (cur == NULL) {
            return;
        }
        if (cur->left || cur->right) { // Non-Leaf
            long long int leftSubtreeSum = 0, rightSubtreeSum = 0, leftProduct = 0, rightProduct = 0, curMaxProduct = INT_MIN;
            if (cur->left) { // If left subtree exists, split left
                rightSubtreeSum = subSum[root] - subSum[cur->left];
                leftSubtreeSum = subSum[cur->left];
                leftProduct = rightSubtreeSum * leftSubtreeSum;
            }
            if (cur->right) { // If right subtree exists, split right
                leftSubtreeSum = subSum[root] - subSum[cur->right];
                rightSubtreeSum = subSum[cur->right];
                rightProduct = rightSubtreeSum * leftSubtreeSum;
            }
            curMaxProduct = max(leftProduct, rightProduct);
            maxProduct = max(curMaxProduct, maxProduct);
        }
        splitTree(cur->left, subSum, maxProduct, root);
        splitTree(cur->right, subSum, maxProduct, root);
        if (cur->left == NULL && cur->right == NULL) { // Leaf
            return;
        }
    }
    
    int traverseTree(TreeNode *cur, unordered_map<TreeNode*, int> &subSum) {
        if (cur == NULL) {
            return 0;
        }
        if (cur->left == NULL && cur->right == NULL) { // Leaf
            subSum.insert({cur, 
            cur->val + traverseTree(cur->left, subSum) + traverseTree(cur->right, subSum)});
            return subSum[cur];
        }
        subSum.insert({cur, 
        cur->val + traverseTree(cur->left, subSum) + traverseTree(cur->right, subSum)});
        return subSum[cur];
    }
};