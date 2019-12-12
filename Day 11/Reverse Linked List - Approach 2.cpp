//Question Link ---> https://leetcode.com/problems/delete-node-in-a-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        queue<int> q;
        FillQueueThenReverse(head, q);
        return head;
    }
    
    void FillQueueThenReverse(ListNode* cur, queue<int> &q) {
        if (!cur) return;
        q.push(cur->val);
        FillQueueThenReverse(cur->next, q);
        cur->val = q.front();
        q.pop();
    }
};
