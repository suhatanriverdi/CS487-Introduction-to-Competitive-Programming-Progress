// Question Link ---> https://leetcode.com/problems/find-bottom-left-tree-value/
// Day #14
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
		queue<pair<int, TreeNode*>> q; // <Level, Node>
		q.push({1, root}); // <Level 1, Root Value>
		pair<int, int> mostBottomLeftValue = {1, root->val}; // <Level, Value>
		while (!q.empty()) {
			pair<int, TreeNode*> currentNode = q.front();
			q.pop();
			if (currentNode.second->left) {
				q.push({currentNode.first + 1, currentNode.second->left});
				pair<int, TreeNode*> tempLeft = q.back();
				if (tempLeft.first > mostBottomLeftValue.first) {
					mostBottomLeftValue.first = tempLeft.first; // Update level
					mostBottomLeftValue.second = tempLeft.second->val; // Update Node's Value
				}
			}
			if (currentNode.second->right) {
				q.push({currentNode.first + 1, currentNode.second->right});
				pair<int, TreeNode*> tempLeft = q.back();
				if (tempLeft.first > mostBottomLeftValue.first) {
					mostBottomLeftValue.first = tempLeft.first; // Update level
					mostBottomLeftValue.second = tempLeft.second->val; // Update Node's Value
				}				
			}
		}
		return mostBottomLeftValue.second;
    }
};