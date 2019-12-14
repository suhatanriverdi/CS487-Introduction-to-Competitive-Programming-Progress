// Codeforces Codeforces Round #604 (Div. 2)
// Question Link ---> https://codeforces.com/contest/1265/problem/B
// Day #13 #Contest 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int sz;
		string res;
		cin >> sz;
		vector<int> v(sz);
		for (int i = 0; i < sz; i++) { int temp; cin >> temp; v[temp - 1] = i; }
		if (sz == 1 || sz == 2) { cout << (sz == 1 ? "1" : "11") << endl; continue; }
		res += '1'; // m = 1 is always exists
		int minIdx = sz, maxIdx = -1;
		int where1 = v[0], where2 = v[1];
		minIdx = min(where1, where2);
		maxIdx = max(where1, where2);
		int diff = abs(minIdx - maxIdx);
		if (diff == (1)) res += '1';
		else res += '0';
		for (int i = 3; i < sz; i++) { // 1..  2 3 4 5  ..6
			int cur_i_Idx = v[i - 1];
			minIdx = min(cur_i_Idx, minIdx);
			maxIdx = max(cur_i_Idx, maxIdx);
			diff = abs(minIdx - maxIdx);
			if (diff == (i - 1)) res += '1';
			else res += '0';
		}
		res += '1'; // m = n is always exists
		cout << res << endl;
	}
	return 0;
}