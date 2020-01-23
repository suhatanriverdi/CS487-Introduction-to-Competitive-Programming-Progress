// Question Link ---> https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Day #14
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *newTree = NULL;
        for (auto node : preorder) {
            newTree = insertBST(newTree, node);
        }
        return newTree;
    }
    
    TreeNode* insertBST(TreeNode *cur, int key) {
        if (cur == NULL) {
            TreeNode* newNode = new TreeNode(key);
            return newNode;
        }
        if (key < cur->val) {
            cur->left = insertBST(cur->left, key);
        }
        else {
            cur->right = insertBST(cur->right, key);
        }
        return cur;
    }
};