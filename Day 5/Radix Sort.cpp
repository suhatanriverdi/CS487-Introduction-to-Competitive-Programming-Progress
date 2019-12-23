// Counting Sort
// Day #5
// Counting sort is a linear time sorting algorithm
// that sorts in O(n+k) time when elements are in range from 1 to k.
#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> &vec, int range) {
	vector<int> cnt(10, 0);
	for (int i = 0; i < range; i++) cnt[vec[i]]++;
	int idx = 0;
	for (int i = 0; i < range; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			vec[idx++] = i;
		}
	}
}

int main(void) {
	vector<int> vec = { 3, 2, 1, 4 };
	countingSort(vec, 4);
	cout << "After Sorting: ";
	for (auto i : vec) cout << i << " ";
}