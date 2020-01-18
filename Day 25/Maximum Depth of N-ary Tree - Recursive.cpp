// Question Link ---> https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Day #25
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 1;
        for (auto node : root->children) {
            depth = max(maxDepth(node) + 1, depth);
        }
        return depth;
    }
};