// Question Link ---> https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Day #9
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> ops = {"+", "-", "/", "*"};
        stack<int> s;
        for (auto i : tokens) {
            if (!ops.count(i)) s.push(stoi(i));
            else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if (i == "+") s.push(a + b);
                if (i == "-") s.push(a - b);
                if (i == "*") s.push(a * b);
                if (i == "/") s.push(a / b);
            }
        }
        return s.top();
    }
};