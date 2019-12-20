//Question Link ---> https://leetcode.com/problems/design-linked-list/
// Day #11
#include <iostream>
using namespace std;

class MyLinkedList {
private:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

public:
	/** Initialize your data structure here. */
	int size = 0;
	ListNode* head = new ListNode(0);
	MyLinkedList() {}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index >= size) return -1;
		ListNode* walk = head->next;
		for (int i = 0; i < index; i++, walk = walk->next);
		return walk->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode* temp = head->next;
		head->next = new ListNode(val);
		head->next->next = temp;
		size++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode* walk = head;
		while (walk->next != NULL) walk = walk->next;
		walk->next = new ListNode(val);
		size++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index > size) return;
		ListNode* walk = head;
		for (int i = 0; i < index; i++) walk = walk->next;
		ListNode* temp = walk->next;
		walk->next = new ListNode(val);
		walk->next->next = temp;
		size++;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= size) return;
		ListNode* walk = head;
		for (int i = 0; i < index; i++, walk = walk->next);
		ListNode* temp = walk->next;
		walk->next = temp->next;
		delete temp;
		size--;
	}

	void printList() {
		ListNode* walk = head;
		while (walk != NULL) {
			cout << walk->val << " ";
			walk = walk->next;
		}
		cout << endl;
	}
};

int main(void) {
	MyLinkedList* obj = new MyLinkedList();
	obj->addAtHead(1);
	obj->addAtTail(3);
	obj->printList();
	obj->addAtIndex(1, 2);
	obj->printList();
	cout << endl << obj->get(1) << endl;
	obj->deleteAtIndex(1); // 1->3
	obj->printList();
	cout << endl << obj->get(1) << endl;
	return 0;
}