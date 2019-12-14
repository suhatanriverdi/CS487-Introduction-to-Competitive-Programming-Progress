// Question Link ---> http://codeforces.com/contest/1272/problem/A
// Codeforces Round #605 (Div. 3)
// Day #17 #Contest 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcDst(int a, int b, int c) {
	return abs(a - b) + abs(a - c) + abs(b - c);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	vector<int> v(3);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 3; i++) cin >> v[i];
		if ((v[0] == v[1] && v[0] == v[2] && v[1] == v[2])) {
			cout << "0\n"; continue;
		}
		sort(v.begin(), v.end());
		if (v[0] == v[1]) { // 3 3 4
			if (abs(v[0] - v[2]) <= 2) { cout << "0\n"; continue; }
			v[0]++;  v[1]++; v[2]--;
			cout << calcDst(v[0], v[1], v[2]) << "\n"; continue;
		}

		if (v[1] == v[2]) { // 1 2 2
			if (abs(v[0] - v[2]) <= 2) { cout << "0\n"; continue; }
			v[1]--;  v[2]--; v[0]++;
			cout << calcDst(v[0], v[1], v[2]) << "\n"; continue;
		}

		if (v[0] > v[1]) v[0]--;
		else if (v[0] < v[1]) v[0]++;
		if (v[2] > v[1]) v[2]--;
		else if (v[2] < v[1]) v[2]++;
		cout << calcDst(v[0], v[1], v[2]) << "\n";
	}
	return 0;
}