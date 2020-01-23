// Question Link ---> https://leetcode.com/problems/most-frequent-subtree-sum/
// Day #24
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        map<int, int> freqMap; // {nodeVal, freq}
        traverse(root, freqMap);
        priority_queue<pair<int, int>> freqQueue;
        for (auto i : freqMap) {
            freqQueue.push({i.second, i.first});
        }
        vector<int> res;
        int curMostFreq = freqQueue.top().first;
        res.push_back(freqQueue.top().second);
        freqQueue.pop();
        while (!freqQueue.empty()) {
            int tempFreq = freqQueue.top().first;
            if (tempFreq == curMostFreq) {
                res.push_back(freqQueue.top().second);
                freqQueue.pop();
            }
            else {
                break;
            }
        }
        return res;
    }
    
    void traverse(TreeNode *cur, map<int, int> &freqMap) {
        if (cur == NULL) {
            return;
        }
        freqMap[subTreeSum(cur)]++;
        traverse(cur->left, freqMap);
        traverse(cur->right, freqMap);
    }
    
    int subTreeSum(TreeNode *cur) {
        if (cur == NULL) {
            return 0;
        }
        return cur->val + subTreeSum(cur->left) + subTreeSum(cur->right);
    }
};