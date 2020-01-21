// Counting Sort
// Day #5
// Counting sort is a linear time sorting algorithm
// That sorts in O(n+k) time when elements are in range from 1 to k.
#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& unsortedArray, int range) {
	vector<int> countArray(range + 1, 0); // Counting Array
	// Store the count of each element
	for (int i = 0; i < unsortedArray.size(); i++) {
		countArray[unsortedArray[i]]++;
	}
	// Modify the count array by adding the previous counts
	for (int i = 0; i + 1 < countArray.size(); i++) {
		countArray[i + 1] = countArray[i] + countArray[i + 1];
	}
	// Since we have n inputs, we create an array with n places
	// Corresponding values represent the places in the count array
	// We place objects in their correct positions and decrease the count by one
	vector<int> sortedArray(unsortedArray.size());
	for (int i = 0; i < unsortedArray.size(); i++) {
		sortedArray[countArray[unsortedArray[i]] - 1] = unsortedArray[i];
		countArray[unsortedArray[i]]--;
	}
	// We move all elements in sortedArray into unsortedArray, to make unsrotedArray sorted
	for (int i = 0; i < unsortedArray.size(); i++) {
		unsortedArray[i] = sortedArray[i];
	}
}

int main(void) {
	vector<int> numbers = { 3, 2, 1, 4 };
	countingSort(numbers, 4);
	cout << "After Sorting: ";
	for (auto number : numbers) {
		cout << number << " ";
	}
	return 0;
}