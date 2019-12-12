// Question Link ---> https://leetcode.com/problems/search-in-a-binary-search-tree/
// Day #14
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        TreeNode *cur = root;
        if (val == cur->val) return cur;
        if (val > root->val) cur = searchBST(root->right, val);
        if (val < root->val) cur = searchBST(root->left, val);
        return cur;
    }
};