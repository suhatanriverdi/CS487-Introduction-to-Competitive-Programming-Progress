// Question Link ---> https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Day #11
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* walk = head;
        while (walk != NULL && walk->next != NULL) {
            if (walk->val == walk->next->val) walk->next = walk->next->next;
            else walk = walk->next;
        }
        return head;
    }
};