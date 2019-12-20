// Prefix Calculator
// Day #8
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int prefixCalc(string str) {
		unordered_set<string> ops = { "+", "-", "/", "*" };
		stack<string> rev;
		stack<int> s;
		cout << str << endl << endl;
		istringstream iss(str);
		string word;
		while (iss >> word) rev.push(word);
		while (!rev.empty()) {
			string word = rev.top(); rev.pop();
			if (!ops.count(word)) s.push(stoi(word));
			else {
				int b = s.top(); s.pop();
				int a = s.top(); s.pop();
				if (word == "+") s.push(a + b);
				if (word == "-") s.push(a - b);
				if (word == "*") s.push(a * b);
				if (word == "/") s.push(a / b);
			}
		}
		return s.top();
	}
};

int main(void) {
	//"+ 4 * 3 12" -> 40
	string input = "+ 4 * 3 12";
	Solution obj;
	cout << "Result: " << obj.prefixCalc(input);
	return 0;
}