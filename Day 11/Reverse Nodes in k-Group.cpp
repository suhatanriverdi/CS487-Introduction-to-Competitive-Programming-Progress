//Question Link ---> https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode *walk = head;
        for (; walk; len++, walk = walk->next);
        if (k == 1 || head == NULL || head->next == NULL || k > len) {
            return head;
        }
        pair<ListNode*, ListNode*> ret = getRevList(head, k);
        head = ret.first;
        walk = ret.second;
        for (int i = 1; i < len / k; i++) { // Total num of reverse operations
            ret = getRevList(walk->next, k);      
            walk->next = ret.first;
            walk = ret.second;
        }
        return head;
    }
    
    pair<ListNode*, ListNode*> getRevList(ListNode *curHead, int k) {
        if (curHead == NULL || curHead->next == NULL) {
            return {curHead, curHead->next};
        }
        ListNode *back = curHead, *mid = curHead->next, *front = NULL;
        for (int j = 0; mid && j < k - 1; j++) {
            front = mid->next;
            mid->next = back;
            back = mid;
            mid = front;
        }
        curHead->next = mid;
        ListNode *lastNodeNext = curHead;
        curHead = back;
        return {curHead, lastNodeNext}; // {headOfReversedList, LastNodeOfReversedList}
    }
};