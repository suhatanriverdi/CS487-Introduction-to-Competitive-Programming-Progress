//Question Link ---> https://leetcode.com/problems/min-stack/
// Day #10
class MinStack {
private:
    stack<int> s;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    void push(int x) {
        s.push(x);
        pq.push(x);
    }
    
    void pop() {
        if (pq.top() == s.top()) pq.pop();
        s.pop();
    }
    
    int top() { return s.top(); }
    int getMin() { return pq.top(); }
};