#include <iostream>
using namespace std;
// Day #1
// Triangle #2
/*
	Input: 5
	Output:     *
			   ***
			  *****
			 *******
			*********
*/
class Solution {
public:
	void printTriangle(int n) {
		for (int i = 1; i <= n; i++) {
			for (int s = 0; s < (n - i); s++) cout << " ";
			for (int j = 0; j < (2*i - 1); j++) cout << "*";
			cout << "\n";
		}
	}
};

int main(void) {
	int n;
	cin >> n;
	Solution obj;
	obj.printTriangle(n);
	return 0;
}