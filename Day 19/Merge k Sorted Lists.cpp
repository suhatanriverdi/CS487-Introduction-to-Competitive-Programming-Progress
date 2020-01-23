// Question Link ---> https://leetcode.com/problems/merge-k-sorted-lists/submissions/
// Day #19
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> filledLists;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                filledLists.push_back(lists[i]);
            }
        }
        
        if (filledLists.size() == 0) {
            return NULL;
        }
        
        if (filledLists.size() == 1) {
            return filledLists[0];
        }
        
        priority_queue<int, vector<int>, greater<int>> heap;
        ListNode *sortedListHead = filledLists[0];
        ListNode *curLastNode = NULL;
        ListNode *walk = sortedListHead;
        while (walk) {
            heap.push(walk->val);
            if (walk->next == NULL) { // Last Node
                curLastNode = walk;
                break;
            }
            walk = walk->next;
        }
        
        for (int i = 1; i < filledLists.size(); i++) {
            if (filledLists[i] != NULL) {                
                walk = filledLists[i];
                curLastNode->next = filledLists[i];
                while (walk) {
                    heap.push(walk->val);
                    if (walk->next == NULL) { // Last Node
                        curLastNode = walk;
                        break;
                    }
                    walk = walk->next;
                }
            }
        }
        
        walk = sortedListHead;
        while (walk) {
            walk->val = heap.top();
            heap.pop();
            walk = walk->next;
        }
        return sortedListHead;
    }
};