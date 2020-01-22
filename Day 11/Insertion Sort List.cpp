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
        if (head == NULL || (head && head->next == NULL)) {
            return head;
        }
        vector<int> arr;
        ListNode *walk = head;
        while (walk) {
            arr.push_back(walk->val);
            walk = walk->next;
        }
        sort(arr.begin(), arr.end());
        walk = head;
        int i = 0;
        while (walk) {
            walk->val = arr[i++];
            walk = walk->next;
        }
        return head;
    }
};