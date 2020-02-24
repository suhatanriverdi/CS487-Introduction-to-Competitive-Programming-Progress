// Question Link ---> https://leetcode.com/problems/linked-list-components/
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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> possibleConnecteds;
        for (auto val : G) {
            possibleConnecteds.insert(val);
        }
        if (head == NULL || head->next == NULL) {
            return (head == NULL ? 0 : (possibleConnecteds.count(head->val) > 0 ? 1 : 0));
        }
        int cnt = 0;
        ListNode *walk = head;
        while (walk != NULL) {
            if (possibleConnecteds.count(walk->val)) {
                cnt++;
            }
            while (walk->next && possibleConnecteds.count(walk->val) && possibleConnecteds.count(walk->next->val)) {
                walk = walk->next; 
            }
            walk = walk->next;
        }
        return cnt;
    }
};