//Question Link ---> https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *L = head, *R = head->next;
        while (L && R) {
            int temp = L->val;
            L->val = R->val;
            R->val = temp;
            if (L->next->next != NULL) L = L->next->next;
            else L = NULL;
            if (R->next != NULL) R = R->next->next;
            else R = NULL;
        }
        return head;
    }
};