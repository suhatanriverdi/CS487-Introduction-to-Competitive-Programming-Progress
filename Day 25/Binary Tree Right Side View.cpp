// Question Link ---> https://leetcode.com/problems/binary-tree-right-side-view/
// Day #25
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<int> rightSideNodes = { root->val };
        while (!nodes.empty()) {
            int levelWidth = nodes.size();
            while (levelWidth--) {                
                TreeNode* currentNode = nodes.front();
                nodes.pop();
                if (currentNode->right) {
                    nodes.push(currentNode->right);
                }
                if (currentNode->left) {
                    nodes.push(currentNode->left);
                }
            }
            if (!nodes.empty()) {
                rightSideNodes.push_back(nodes.front()->val);
            }
        }
        return rightSideNodes;
    }
};