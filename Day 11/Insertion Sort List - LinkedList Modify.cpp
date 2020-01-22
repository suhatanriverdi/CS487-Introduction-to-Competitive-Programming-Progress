//Question Link ---> https://leetcode.com/problems/insertion-sort-list/
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newListHead = new ListNode(head->val);
        ListNode *walk = head->next;
        while (walk) {
            newListHead = insertNode(newListHead, walk->val);
            walk = walk->next;
        }
        return newListHead;
    }
    
    ListNode* insertNode(ListNode *newListHead, int newVal) {
        if (newVal < newListHead->val) {
            ListNode *newNode = new ListNode(newVal);
            newNode->next = newListHead;
            newListHead = newNode;
            return newListHead;
        }
        
        if (newListHead && newListHead->next == NULL) { // head -> 1 -> Null -_
            ListNode *newNode = new ListNode(newVal);
            newListHead->next = newNode;
            return newListHead;
        }
        
        ListNode *walk = newListHead;
        while (walk->next) {
            if (newVal < walk->next->val) {
                ListNode *temp = walk->next;
                walk->next = new ListNode(newVal);
                walk->next->next = temp;
                return newListHead;
            }
            walk = walk->next;
        }
        ListNode *newNode = new ListNode(newVal);
        walk->next = newNode;
        return newListHead;
    }
};