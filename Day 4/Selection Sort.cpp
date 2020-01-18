// Selection Sort
// Day #4
// In every iteration of selection sort, the minimum element(considering ascending order) 
// from the unsorted subarray is picked and moved to the sorted subarray.
// Time ComplexityO(n^2), UNSTABLE, In-Place
#include <iostream>    
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int> &numbers) {
	for (int sortedIndex = 0; sortedIndex < numbers.size(); sortedIndex++) {
		for (int unSortedIndex = sortedIndex + 1; unSortedIndex < numbers.size(); unSortedIndex++) {
			if (numbers[unSortedIndex] < numbers[sortedIndex]) {
				swap(numbers[sortedIndex], numbers[unSortedIndex]);
			}
		}
	}
}

int main(void) {
	vector<int> numbers = { 3, 2, 1, 4 };
	selectionSort(numbers);
	cout << "After Sorting: ";
	for (auto elem : numbers) {
		cout << elem << " ";
	}
}