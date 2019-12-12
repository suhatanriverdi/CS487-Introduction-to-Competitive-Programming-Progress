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
        if (!root || root->val == val) return root;
        if (val > root->val) return searchBST(root->right, val);
        if (val < root->val) return searchBST(root->left, val);
        return NULL;
    }
};