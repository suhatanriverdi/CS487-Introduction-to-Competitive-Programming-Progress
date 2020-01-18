// Question Link ---> https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
// Day #25
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        int sum = 0;
        while (!nodes.empty()) {
            TreeNode* currentNode = nodes.front();
            nodes.pop();
            if (currentNode->val % 2 == 0) { // Possible Even Grandparent
                sum += sumOfValuesWithEvenGrandParent(currentNode);
            }
            if (currentNode->right) {
                nodes.push(currentNode->right);
            }
            if (currentNode->left) {
                nodes.push(currentNode->left);
            }
        }
        return sum;
    }
    
    int sumOfValuesWithEvenGrandParent(TreeNode *grandNode) {
        int sumOfValues = 0;
        if (grandNode->right) {
            if (grandNode->right->right) {
                sumOfValues += grandNode->right->right->val;
            }
            if (grandNode->right->left) {
                sumOfValues += grandNode->right->left->val;
            }
        }
        if (grandNode->left) {
            if (grandNode->left->left) {
                sumOfValues += grandNode->left->left->val;
            }
            if (grandNode->left->right) {
                sumOfValues += grandNode->left->right->val;
            }
        }
        return sumOfValues;
    }
};