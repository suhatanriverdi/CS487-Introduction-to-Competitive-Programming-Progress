// Question Link ---> https://leetcode.com/problems/balance-a-binary-search-tree/
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inOrderArr(root, sorted); // Save values in sorted order, O(N)
        return balancedBST(sorted, 0, sorted.size() - 1);
    }

    // Constructs balanced binary search tree from sorted array
    TreeNode* balancedBST(vector<int> &arr, int L, int R) {
        if (L <= R) {
            int M = (R + L) / 2; // Find midVal
            TreeNode *cur = new TreeNode(arr[M]); // Create Node
            cur->right = balancedBST(arr,  M + 1,  R);
            cur->left = balancedBST(arr,  L,  M - 1);
            return cur;
        }
        return NULL;
    }
    
	// Saves values in sorted increasing order
    void inOrderArr(TreeNode *cur, vector<int> &sorted) {
        if (cur == NULL) {
            return;
        }
        inOrderArr(cur->left, sorted);
        sorted.push_back(cur->val);
        inOrderArr(cur->right, sorted);
    }
};