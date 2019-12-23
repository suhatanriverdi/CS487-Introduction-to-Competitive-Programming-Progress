// Quick Sort
// The lower bound for Comparison based sorting algorithm (Merge Sort, Heap Sort, Quick-Sort .. etc) is Ω(nLogn), i.e., 
// they cannot do better than nLogn.
// Day #4
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& vec, int low, int high) {
	int pivot = vec[high];
	int i = low;
	for (int j = low; j <= high - 1; j++) {
		if (vec[j] < pivot) {
			swap(vec[j], vec[i]);
			i++;
		}
	}
	swap(vec[high], vec[i]);
	return i;
}

void quickSort(vector<int> &vec, int low, int high) {
	if (low < high) {
		int pivot = partition(vec, low, high);
		quickSort(vec, low, pivot - 1);
		quickSort(vec, pivot + 1, high);
	}
}

int main(void) {
	vector<int> vec = { 3, 2, 1, 4 };
	quickSort(vec, 0, vec.size() - 1);
	cout << "After Sorting: ";
	for (auto i : vec) cout << i << " ";
}