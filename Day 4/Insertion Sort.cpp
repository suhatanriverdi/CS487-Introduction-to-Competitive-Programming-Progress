// Insertion Sort
// Day #4
// Time ComplexityO(n^2), In-Place and Stable
#include <iostream>    
#include <vector>
#include <algorithm>
using namespace std;
/* Steps;
-> 3 | 2, 1, 4
-> 2, 3 | 1, 4
-> 1, 2, 3 | 4
-> 1, 2, 3, 4 |
*/
void insertionSort(vector<int>& numbers) {
	// We have sorted and unsorted parts,
	// That's why we start from index 1
	// Sorted | Unsorted
	//	  0     1  2  3   -> Indexes
	//    3   | 2, 1, 4	  -> Numbers
	int firstUnsortedElement, sortedIndex;
	for (int i = 1; i < numbers.size(); i++) {
		firstUnsortedElement = numbers[i]; // We take first unsorted number
		sortedIndex = i - 1; // Backward Sorted Array Index for while loop
		while (sortedIndex >= 0 && firstUnsortedElement < numbers[sortedIndex]) {
			numbers[sortedIndex + 1] = numbers[sortedIndex];
			sortedIndex--;
		}
		numbers[sortedIndex + 1] = firstUnsortedElement;
	}
}

int main(void) {
	vector<int> numbers = { 3, 2, 1, 4 };
	insertionSort(numbers);
	cout << "After Sorting: ";
	for (auto elem : numbers) {
		cout << elem << " ";
	}
}