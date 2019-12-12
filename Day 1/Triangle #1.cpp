#include <iostream>
using namespace std;
// Day #1
// Triangle #1
/*
	Input: 5
	Output: *
			**
			***
			****
			*****
*/
class Solution {
public:
	void printTriangle(int n) {
		if (n == 0) return;
		printTriangle(n - 1);
		for (int i = 0; i < n; i++) cout << "*";
		cout << "\n";
	}
};

int main(void) {
	int n;
	cin >> n;
	Solution obj;
	obj.printTriangle(n);
	return 0;
}