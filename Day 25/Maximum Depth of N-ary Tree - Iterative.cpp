// Question Link ---> https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Day #25
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        queue<Node*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int currentQueueSize = nodes.size();
            while (currentQueueSize--) {      
                Node* currentNode = nodes.front();
                nodes.pop();
                for (auto child : currentNode->children) {
                    nodes.push(child);
                }
            }
            depth++;
        }
        return depth;
    }
};