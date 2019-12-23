// Radix Sort
// Day #5
// Time Complexity θ(nk)
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

void radixSort(vector<int> &arr, int n, int max) {
	int i, j, m, p = 1, index, temp, count = 0;
	list<int> pocket[10]; //radix of decimal number is 10
	for (i = 0; i < max; i++) {
		m = pow(10, i + 1);
		p = pow(10, i);
		for (j = 0; j < n; j++) {
			temp = arr[j] % m;
			index = temp / p; //find index for pocket array
			pocket[index].push_back(arr[j]);
		}
		count = 0;
		for (j = 0; j < 10; j++) { //delete from linked lists and store to array
			while (!pocket[j].empty()) {
				arr[count] = *(pocket[j].begin());
				pocket[j].erase(pocket[j].begin());
				count++;
			}
		}
	}
}

int main(void) {
	vector<int> vec = { 3, 2, 1, 4 };
	radixSort(vec, 4, 4);
	cout << "After Sorting: ";
	for (auto i : vec) cout << i << " ";
}