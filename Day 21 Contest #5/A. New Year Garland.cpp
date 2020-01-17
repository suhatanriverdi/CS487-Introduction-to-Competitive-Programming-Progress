// Educational Codeforces Round 79 (Rated for Div. 2)
// Question Link ---> https://codeforces.com/contest/1279/problem/A
// Day #21 #Contest 5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		if (v[0] + v[1] + 1 >= v[2]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}