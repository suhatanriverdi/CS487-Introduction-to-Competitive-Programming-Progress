// Question Link ---> https://leetcode.com/problems/merge-two-sorted-lists/
// Day #11
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (!l1 || !l2) return (!l1 ? l2 : l1);
    	vector<int> vec;
    	fillVec(l1, vec);
    	fillVec(l2, vec);
    	sort(vec.begin(), vec.end());
    	return appendList(vec);
    }
    
    ListNode* appendList(vector<int> &vec) {    	
    	ListNode* newList = NULL;
		for (auto &i : vec) {
			if (!newList) newList = new ListNode(i);
			else {
    			ListNode* walk = newList;
		    	while (walk->next != NULL) {
		    		walk = walk->next;
				}
				walk->next = new ListNode(i);
			}
		}
		return newList;
	}
    
    void fillVec(ListNode *list, vector<int> &vec) {
    	ListNode *walk = list;
    	while (walk != NULL) {
    		vec.push_back(walk->val);
    		walk = walk->next;
		}
	}
    
    void printList(ListNode *list) {
    	ListNode *walk = list;
    	while (walk != NULL) {
    		cout << " " << walk->val;
    		walk = walk->next;
		}
	}
};

int main(void) {
	ListNode *newList;
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);

	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	
	Solution obj;
	newList = obj.mergeTwoLists(l1, l2);
	obj.printList(newList);
	return 0;
}
