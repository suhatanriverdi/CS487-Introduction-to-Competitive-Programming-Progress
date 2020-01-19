// Question Link ---> https://leetcode.com/problems/binary-tree-level-order-traversal/
// Day #25

// Longer Production Coding Style Version
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return levelOrderValues;
    }
};


// Shorter Competitive Programming Coding Style Version
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root, vector<vector<int>> res = {}) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> lvl;
            int sz = q.size();
            while (sz--) {
                TreeNode* cur = q.front(); q.pop();
                lvl.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            } res.push_back(lvl);
        }
        return res;
    }
};