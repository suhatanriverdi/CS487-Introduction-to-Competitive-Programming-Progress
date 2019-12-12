// Question Link ---> https://leetcode.com/contest/weekly-contest-138/problems/distant-barcodes/
// Day #8
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
	stack<char> list;
	char top() return list.top();
	bool isPair(char open, char close){
		if (open == '(' && close == ')') return true; 
		else if (open == '{' && close == '}') return true; 
		else if (open == '[' && close == ']') return true; 
		return false; 
	}
	
	bool isValid(string s) {
		if (s == "") return true;
		if (s.length() == 1 || ( s.length() == 1 && s[0] == ')' || s[0] == '}' || s[0] == ']' )) return false;
		else {
			for (int i=0; i<s.size(); i++) {
				if (s[i] == '(' || s[i] == '[' || s[i] == '{') list.push(s[i]);
				else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
					if (!list.empty() && isPair(list.top(), s[i])) list.pop();
					else return false;
				}
			}
			if (list.empty()) return true;
			else return false;
		}
	}
};

int main(void) {
	Solution obj;
	cout << obj.isValid("((");
	return 0;
}
