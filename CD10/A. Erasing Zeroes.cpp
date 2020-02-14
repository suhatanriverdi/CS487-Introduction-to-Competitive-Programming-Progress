#include <iostream>
using namespace std;
// Question Link ---> https://codeforces.com/contest/1303/problem/0
// Educational Codeforces Round 82 (Rated for Div. 2)

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		if (s == "1" || s == "0") {
			cout << "0" << endl;
		}
		else {
			int size = s.size(), l1, r1, cnt0 = 0;
			bool l1found = false, r1found = false;
			for (int i = 0; i < size; i++) { // left 1
				if (s[i] == '1') {
					l1 = i;
					l1found = true;
					break;
				}
			}
			for (int i = size - 1; i >= 0; i--) { // right 1
				if (s[i] == '1') {
					r1 = i;
					r1found = true;
					break;
				}
			}
			if ((l1found == false && r1found == false) || (l1 == r1)) { // no "1"
				cout << "0" << endl;
			}
			else {
				for (int i = l1; i < r1; i++) { // right 1
					if (s[i] == '0') {
						cnt0++;
					}
				}
				cout << cnt0 << endl;
			}
		}
	}
	return 0;
}