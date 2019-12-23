// Merge Sort
// The lower bound for Comparison based sorting algorithm (Merge Sort, Heap Sort, Quick-Sort .. etc) is Ω(nLogn), i.e., 
// they cannot do better than nLogn.
// Day #4
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &vec, int size) {
	if (size > 1) {
		int mid = size / 2;
		int L_size = mid;
		int R_size = size - mid;
		vector<int> L_arr(L_size);
		vector<int> R_arr(R_size);
		for (int l = 0; l < mid; l++) L_arr[l] = vec[l];
		for (int r = mid; r < size; r++) R_arr[r - mid] = vec[r];
		mergeSort(L_arr, L_size);
		mergeSort(R_arr, R_size);
		int L_idx = 0, R_idx = 0, total_idx = 0;
		while (L_idx < L_size && R_idx < R_size) {
			if (L_arr[L_idx] < R_arr[R_idx]) {
				vec[total_idx++] = L_arr[L_idx++];
			}
			else vec[total_idx++] = R_arr[R_idx++];
		}
		while (L_idx < L_size) {
			vec[total_idx++] = L_arr[L_idx++];
		}
		while (R_idx < R_size) {
			vec[total_idx++] = R_arr[R_idx++];
		}
	}
}

int main(void) {
	vector<int> vec = { 3, 2, 1, 4 };
	mergeSort(vec, 4);
	cout << "After Sorting: ";
	for (auto i : vec) cout << i << " ";
}