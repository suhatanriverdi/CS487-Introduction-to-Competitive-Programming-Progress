// Question Link ---> https://leetcode.com/problems/largest-perimeter-triangle/
// Day #6
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// The Triangle Inequality Theorem 
// states that the sum of any 2 sides of a triangle 
// must be greater than the measure of the third side.
// A + B > C
// B + C > A
// A + C > B
// All Above 3 Sets of Sides must satisfy the rule
class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end(), greater<int>());
		for (int i = 0; i + 2 < A.size(); i++) {
			if (canBeTriangle(A[i], A[i + 1], A[i + 2])) return (A[i] + A[i + 1] + A[i + 2]);
		}
		return 0;
	}

	bool canBeTriangle(int a, int b, int c) {
		return (((a + b) > c) && ((b + c) > a) && ((a + c) > b));
	}
};

int main(void) {
	vector<int> A = {2, 1, 2};
	Solution obj;
	cout << "Output: " << obj.largestPerimeter(A);
	return 0;
}