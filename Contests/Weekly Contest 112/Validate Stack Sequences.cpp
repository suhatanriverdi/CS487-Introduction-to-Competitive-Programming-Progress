// Question Link ---> https://leetcode.com/problems/validate-stack-sequences/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        stack<int> validateStack;
        for (auto valPush : pushed) {
            validateStack.push(valPush);
            while (!validateStack.empty() && j < popped.size() && validateStack.top() == popped[j]) {
                j++;
                validateStack.pop();
            }
        }
        return validateStack.empty();
    }
};