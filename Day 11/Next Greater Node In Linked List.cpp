//Question Link ---> https://leetcode.com/problems/next-greater-node-in-linked-list/
// Day #11
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {};
        vector<int> res;
        ListNode *i = head;
        while (i->next) {
            int curMax = i->val, temp = i->val;
            ListNode *j = i->next;
            int R = j->val;
            while (j) {
                R = j->val;
                if (R > curMax) { curMax = R; break; }
                j = j->next;
            }
            if (temp == curMax) res.push_back(0);
            else res.push_back(curMax);
            i = i->next;
        }
        res.push_back(0);
        return res;
    }
};