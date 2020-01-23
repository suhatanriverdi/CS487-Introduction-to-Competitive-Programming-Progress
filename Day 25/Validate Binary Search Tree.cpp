// Question Link ---> https://leetcode.com/problems/validate-binary-search-tree/
// Day #25
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        vector<int> values;
        traveseInOrder(root, values);
        for (int i = 0; i + 1 < values.size(); i++) {
            if (values[i] >= values[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    void traveseInOrder(TreeNode *cur, vector<int> &values) {
        if (cur == NULL) {
            return;
        }
        traveseInOrder(cur->left, values);
        values.push_back(cur->val);
        traveseInOrder(cur->right, values);
    }

};