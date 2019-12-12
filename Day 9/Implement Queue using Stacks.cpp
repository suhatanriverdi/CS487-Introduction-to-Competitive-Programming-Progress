// Question Link ---> https://leetcode.com/problems/implement-queue-using-stacks
// Day #9
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
	stack<int> s;
	stack<int> tempStack;
public:
	/** Push element x to the back of queue. */
	void push(int x) {
	    if (s.size() == 0) s.push(x);
		else {	
			while (!s.empty()) {
				tempStack.push(s.top());
				s.pop();					
			}
			s.push(x);
			while (!tempStack.empty()) {						
				s.push(tempStack.top());
				tempStack.pop();
			}
		}
	}
	
	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int ret = s.top();
		s.pop();
	    return ret;
	}
	
	/** Get the front element. */
	int peek() {
	    return s.top();
	}
	
	/** Returns whether the queue is empty. */
	bool empty() {
	    return s.size() == 0;
	}
};

int main(void) {
	MyQueue q;
	q.push(1);
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(9);
	q.push(11);
	cout <<"Poped: " << q.pop() << endl;
	cout <<"Poped: " << q.pop() << endl;
	cout <<"Poped: " << q.pop() << endl;
	cout <<"Poped: " << q.pop() << endl;
	cout <<"Poped: " << q.pop() << endl;
	cout <<"Poped: " << q.pop() << endl;
	return 0;
}
