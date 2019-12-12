// Question Link ---> https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Day #11
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode walk = head;
        while (walk != null && walk.next != null) {
            if (walk.next.val == walk.val) {
                walk.next = walk.next.next;
            }
            else {
                walk = walk.next; 
            }
        }
        return head;
    }
}