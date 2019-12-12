// Question Link ---> https://leetcode.com/problems/implement-stack-using-queues
// Day #9
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
	queue<int> q;
	int size;
	
public:
	MyStack() {
	    size=0;
	}
	
	/** Push element x onto stack. */
	void push(int x) {
	    if (q.size() == 0) q.push(x);
		else {
			q.push(x);
			for (int i=0; i<size; i++) {
				q.push(q.front());
				q.pop();
			}
		}
		size++;
	}
	
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret = q.front();
		q.pop();
	    return ret;
	}
	
	/** Get the top element. */
	int top() {
	    return q.front();
	}
	
	/** Returns whether the stack is empty. */
	bool empty() {
	    return q.size() == 0;
	}
};

int main(void) {
	MyStack s;
	s.push(1);
	s.push(3);
	s.push(5);
	s.push(7);
	s.push(9);
	cout <<"Poped: " << s.pop() << endl;
	cout <<"Poped: " << s.pop() << endl;
	cout <<"Poped: " << s.pop() << endl;
	cout <<"Poped: " << s.pop() << endl;
	cout <<"Poped: " << s.pop() << endl;
	return 0;
}
