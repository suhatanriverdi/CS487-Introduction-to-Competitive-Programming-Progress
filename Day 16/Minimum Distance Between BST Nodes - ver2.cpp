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
    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        traverseTree(root, vec);
        set<int> s;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                s.insert(abs(vec[i] - vec[j]));
            }
        }
        return *s.begin();
    }
    
    void traverseTree(TreeNode* curr, vector<int> &vec) {
        if (!curr) return;
        vec.push_back(curr->val);
        if (curr->left) traverseTree(curr->left, vec);
        if (curr->right) traverseTree(curr->right, vec);
    }
};