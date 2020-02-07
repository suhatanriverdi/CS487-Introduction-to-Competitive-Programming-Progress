// Question Link ---> https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> sorted = {};
        traversePostOrder(root1, sorted);
        traversePostOrder(root2, sorted);
        sort(sorted.begin(), sorted.end());
        return sorted;
    }
    
    void traversePostOrder(TreeNode* cur, vector<int> &sorted) {
        if (cur == NULL) {
            return;
        }
        traversePostOrder(cur->left, sorted);
        sorted.push_back(cur->val);
        traversePostOrder(cur->right, sorted);
    }
};