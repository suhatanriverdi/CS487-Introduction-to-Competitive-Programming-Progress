// Question Link ---> https://leetcode.com/problems/pancake-sorting/
// Day #6
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> pancakeSort(vector<int> &A) {
		if (A.size() == 1) return {};
		vector<int> sorted = A;
		sort(sorted.begin(), sorted.end());
		if (isSorted(A, sorted)) return {}; // If Already Sorted
		vector<int> pancakeFlips;
		while (A.size() >= 2) {
			int localK = findBiggestIdx(A);
			makeFlips(A, localK, pancakeFlips); // First move biggest to the front then to the end.
		}
		return pancakeFlips;
	}

	int findBiggestIdx(vector<int> &vec) {
		int localMaxIdx = 0, localMaxNum = 0;
		for (int i = 0; i < vec.size(); i++) { 
			if (vec[i] > localMaxNum) {
				localMaxIdx = i;
				localMaxNum = vec[i];
			}
		}
		return localMaxIdx;
	}

	void makeFlips(vector<int> &vec, int k, vector<int> &pancakeFlips) {
		vector<int> newSequence;
		// If biggest num is at the end
		if (k == vec.size() - 1) {
			vec.pop_back();
			return;
		}
		// If biggest is at the front
		if (k == 0) {
			flipReverse(vec, k, pancakeFlips, newSequence);
			if (vec.size() > 0) vec.pop_back();
			return;
		}
		for (int i = k; i >= 0; i--) newSequence.push_back(vec[i]);
		for (int i = k + 1; i < vec.size(); i++) newSequence.push_back(vec[i]);
		pancakeFlips.push_back(k + 1);
		vec = newSequence;
		flipReverse(vec, k, pancakeFlips, newSequence);
		if (vec.size() > 0) vec.pop_back();
	}

	void flipReverse(vector<int> &vec, int k, vector<int> &pancakeFlips, vector<int> &newSequence) {
		newSequence = vec;
		for (int i = newSequence.size() - 1, j = 0; i >= 0 && j < vec.size(); i--, j++) vec[j] = newSequence[i];
		pancakeFlips.push_back(vec.size());
	}

	bool isSorted(vector<int> &vec, vector<int> &sorted) { return (vec == sorted); }
};

int main(void) {
	//vector<int> A = {2, 1}, res;
	vector<int> A = {3, 2, 4, 1}, res;
	//vector<int> A = {3, 2, 1, 4, 5}, res;
	Solution obj;
	res = obj.pancakeSort(A);
	cout << "Output: ";
	for (auto i : res) cout << i << " ";
	return 0;
}