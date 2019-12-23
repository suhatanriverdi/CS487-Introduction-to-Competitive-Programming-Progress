// Insertion Sort
// Day #4
// Time ComplexityO(n^2)
#include <iostream>    
#include <vector>
#include <algorithm>
using namespace std;
/* Steps;
-> 3, 2, 1, 4
-> 2, 3, 1, 4
-> 1, 2, 3, 4
-> 1, 2, 3, 4
*/
void insertionSort(vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++) {
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && key < vec[j]) {
			vec[j + 1] = vec[j];
			j = j - 1;
		}
		vec[j + 1] = key;
	}
}

int main(void) {
	vector<int> vec = { 3, 2, 1, 4 };
	insertionSort(vec);
	cout << "After Sorting: ";
	for (auto i : vec) cout << i << " ";
}