// Radix Sort
// Day #5
// Time Complexity θ(nk)
#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int>& numbers) {
	for (auto num : numbers) {
		cout << num << " ";
	}
	cout << endl;
}

void countSort(vector<int> &arr, int exp) {
	vector<int> countArray(10, 0); // Counting Array
	// Store the count of each element
	for (int i = 0; i < arr.size(); i++) {
		countArray[ (arr[i] / exp) % 10 ]++; // 1 % 10 = 1
	}

	// Modify the count array by adding the previous counts
	for (int i = 0; i + 1 < 10; i++) {
		countArray[i + 1] += countArray[i];
	}
	cout << "\t countArr: "; printArr(countArray); cout << endl;
	// Build the output array
	vector<int> sortedArray(arr.size());
	for (int i = arr.size() - 1; i >= 0; i--) {
		sortedArray[countArray[ (arr[i] / exp) % 10 ] - 1] = arr[i];
		countArray[ (arr[i] / exp) % 10 ]--;
	}

	//// WRONG USAGE! (This is true in Counting Sort but wrong here!)
	//vector<int> sortedArray(arr.size());
	//for (int i = 0; i < arr.size(); i++) {
	//	sortedArray[countArray[(arr[i] / exp) % 10] - 1] = arr[i];
	//	countArray[(arr[i] / exp) % 10]--;
	//}

	// We move all elements in sortedArray into unsortedArray, to make unsrotedArray sorted
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = sortedArray[i];
	}
}

// Finds maximum value in array
int getMaximumValue(vector<int> &arr) {
	int maxValue = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] > maxValue) {
			maxValue = arr[i];
		}
	}
	return maxValue;
}

void radixSort(vector<int> &arr) {
	int maxValue = getMaximumValue(arr);
	// Run counting sort for every digit
	// Instead of passing Digit Number
	// Exp is passed. exp is 10 ^ i
	// Where i is current digit number (ith digit)
	for (int exp = 1; (maxValue / exp) > 0; exp *= 10) {
		countSort(arr, exp);
		cout << "After " << exp << "th digit sorted: ";
		printArr(arr);
	}
}

int main(void) {
	//vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
	//vector<int> arr = { 802, 24, 2};
	vector<int> arr = { 1, 24, 2, 15, 0}; 
	radixSort(arr);
	cout << "After Sorting: ";
	for (auto value : arr) {
		cout << value << " ";
	}
	return 0;
}