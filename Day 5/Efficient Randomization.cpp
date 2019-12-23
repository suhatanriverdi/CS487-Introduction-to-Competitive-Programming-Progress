// Efficient Randomization
// Day #5
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

void generateRandomArray(vector<int> &vec, int range) {
	for (int i = 0; i < range; i++) vec[i] = i;
	random_device rd;
	mt19937 rng(rd());
	for (int i = 0; i < range; i++) {
		uniform_int_distribution<int> uni(i, range - 1); // guaranteed unbiased
		int _rand = uni(rng);
		swap(vec[i], vec[_rand]);
	}
}

int main(void) {
	vector<int> vec = { 0, 1, 2, 3 };
	generateRandomArray(vec, 4);
	cout << "After Shuffling: ";
	for (auto i : vec) cout << i << " ";
}