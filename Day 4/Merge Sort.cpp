// Merge Sort
// Day #4
// Divide and conquer:
// 1 - Let the first half of the array be sorted
// 2 - Let the second half of the array be sorted
// 3 - Let’s merge them together
// Time ComplexityO(nlog(n)), Stable, NOT In-Place
#include <iostream>    
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
	vector<int> leftArr, rightArr;
	for (int i = left; i <= mid; i++) {
		leftArr.push_back(arr[i]);
	}
	for (int i = mid + 1; i <= right; i++) {
		rightArr.push_back(arr[i]);
	}
	leftArr.push_back(INT_MAX);
	rightArr.push_back(INT_MAX);
	for (int i = left, tmpLeftIdx = 0, tmpRightIdx = 0; i <= right; i++) {
		if (leftArr[tmpLeftIdx] <= rightArr[tmpRightIdx]) {
			arr[i] = leftArr[tmpLeftIdx++];
		}
		else {
			arr[i] = rightArr[tmpRightIdx++];
		}
	}
}

void mergeSort(vector<int> &arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main(void) {
	vector<int> numbers = { 3, 2, 1, 4 };
	int left = 0, right = numbers.size() - 1;
	mergeSort(numbers, left, right);
	cout << "After Sorting: ";
	for (auto elem : numbers) {
		cout << elem << " ";
	}
}