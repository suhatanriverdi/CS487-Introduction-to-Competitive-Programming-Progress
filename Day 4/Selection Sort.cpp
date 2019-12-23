// Selection Sort
// Day #4
// In every iteration of selection sort, the minimum element(considering ascending order) 
// from the unsorted subarray is picked and moved to the sorted subarray.
// Time ComplexityO(n^2)
#include <iostream>    
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		int minIdx = i;
		for (int j = i + 1; j < vec.size(); j++) if (vec[j] < vec[minIdx]) minIdx = j;
		swap(vec[minIdx], vec[i]);
	}
}

int main(void) {
	vector<int> vec = { 3, 2, 1, 4 };
	selectionSort(vec);
	cout << "After Sorting: ";
	for (auto i : vec) cout << i << " ";
}