// Question Link ---> https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Day #19
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
		int currentMax = 0;
		for (int i = 0; i < A.size(); i++) currentMax = max(A[i], currentMax);
		for (int i = 0; i < A.size(); i++) if (A[i] == currentMax) return i;
    }
};

int main(void) {
	vector<int> vec = {0,2,1,0};
	Solution obj;
	cout << "\nOutput: " << obj.peakIndexInMountainArray(vec);
    return 0;
}

