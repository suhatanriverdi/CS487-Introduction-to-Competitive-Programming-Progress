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
        return search(root, val);
    }
    
    TreeNode* search(TreeNode* current, int n) {
        if (current == NULL || current->val == n) return current;
        if (n > current->val) return search(current->right, n);
        if (n < current->val) return search(current->left, n);   
        return NULL;
    }
};