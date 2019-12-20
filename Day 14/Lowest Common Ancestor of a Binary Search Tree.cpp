// Question Link ---> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Day #14
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        vector<TreeNode*> p1, p2;
        bs(root, p->val, p1); 
        bs(root, q->val, p2);
        int i = 0; for (; i < (p1 < p2 ? p1.size() : p2.size()) && p1[i] == p2[i]; i++) {};
        return p1[i - 1];
    }
    
    void bs(TreeNode* cur, int num, vector<TreeNode*> &path) {
        if (!cur) return;
        if (cur->val == num) path.push_back(cur);
        if (num > cur->val && cur->right) { path.push_back(cur); bs(cur->right, num, path); }
        if (num < cur->val && cur->left) { path.push_back(cur); bs(cur->left, num, path); }
    }
};