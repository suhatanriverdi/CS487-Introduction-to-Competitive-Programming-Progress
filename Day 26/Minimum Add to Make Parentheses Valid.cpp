// Question Link ---> https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Day #26

// Stack Solution
class Solution {
public:
    int minAddToMakeValid(string S) {
    	int size = S.size(), cnt = 0;
    	if (size <= 1) { // "("
    		return size;
    	}
    	stack<char> parStack;
        for (auto cur : S) {
        	if (cur == '(') {
        		parStack.push(cur);
        	} 
        	else { // ')'
        		if (parStack.empty()) {
        			cnt++;
        		}
        		if (parStack.size() > 0) {
					parStack.pop();
        		}
        	}
        }
        return cnt + parStack.size();
    }
};

// No Stack Solution
class Solution {
public:
    int minAddToMakeValid(string S) {
    	int opens = 0, tmp = 0;
        for (auto cur : S) {
        	if (cur == '(') {
        		opens++;
        	} 
        	else { // ')'
        		if (opens > 0) {
        			opens--;
        		}
        		else {
        			tmp++;
        		}
        	}
        }
        return opens + tmp;
    }
};