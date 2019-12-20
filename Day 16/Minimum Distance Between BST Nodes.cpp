// Question Link ---> https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Day #16
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
    int minDiffInBST(TreeNode* root, int locMin = INT_MAX) {
        vector<int> v;
        postOrder(root, v);
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                locMin = min(locMin, abs(v[i] - v[j]));
            }
        }
        return locMin;
    }
    
    void postOrder(TreeNode* cur, vector<int> &v) {
        if (!cur) return;
        postOrder(cur->left, v);
        postOrder(cur->right, v);
        v.push_back(cur->val);
    }
};