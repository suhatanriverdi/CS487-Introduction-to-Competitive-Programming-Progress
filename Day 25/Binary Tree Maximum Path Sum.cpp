// Question Link ---> https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Day #25
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL || (root->right == NULL && root->left == NULL)) {
            return (root ? root->val : 0);
        }
        int maxPathSums = root->val;
        findMaxPathForAllNodes(root, maxPathSums);
        return maxPathSums;
    }
    
    void findMaxPathForAllNodes(TreeNode* cur, int &maxPathSums) {
        if (cur == NULL) {
            return;
        }
        int leftMaxPathSum = cur->val, rightMaxPathSum = cur->val;
        traverseSubTree(cur->left, leftMaxPathSum, cur->val);
        traverseSubTree(cur->right, rightMaxPathSum, cur->val);
        int curVal = cur->val, left = leftMaxPathSum, right = rightMaxPathSum;
        maxPathSums = max(maxPathSums, max(curVal, max(right, max(left, right + left - curVal))));
        findMaxPathForAllNodes(cur->right, maxPathSums);
        findMaxPathForAllNodes(cur->left, maxPathSums);
    }
    
    void traverseSubTree(TreeNode* cur, int &localMaxPathSum, int curPathSum) {
        if (cur == NULL) {
            return;
        }
        int pathSumByFar = curPathSum + cur->val;
        localMaxPathSum = max(pathSumByFar, localMaxPathSum);
        traverseSubTree(cur->right, localMaxPathSum, pathSumByFar);
        traverseSubTree(cur->left, localMaxPathSum, pathSumByFar);
        curPathSum -= cur->val;
    }
};