// Question Link ---> https://leetcode.com/problems/rotting-oranges/
// Day #25
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> levelOrderValues;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> nodesAtSameLevel;
            int currentQueueSize = nodes.size();
            while (currentQueueSize--) {
                TreeNode* currentNode = nodes.front();
                nodesAtSameLevel.push_back(currentNode->val);
                nodes.pop();
                if (currentNode->left) {
                    nodes.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodes.push(currentNode->right);
                }
            }
            levelOrderValues.push_back(nodesAtSameLevel);
        }
        reverse(levelOrderValues.begin(),levelOrderValues.end());
        return levelOrderValues;
    }
};