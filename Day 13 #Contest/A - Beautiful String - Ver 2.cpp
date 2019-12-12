// Codeforces Codeforces Round #604 (Div. 2)
// Question Link ---> https://codeforces.com/contest/1265/problem/A
// Day #13 #Contest 1
#include <iostream>
#include <unordered_set>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) { // a, b, c, ?
		string s;
		cin >> s;
		if (s == "?") {
			cout << "a\n";
			continue;
		}
		bool isNotBeautiful = false;
		for (int i = 0; i + 1 < s.size(); i++) {
			if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1]) {
				isNotBeautiful = true;
				break;
			}
		}
		if (isNotBeautiful) {
			cout << "-1\n";
		}
		else {
			for (int i = 0; i < s.size(); i++) {
				unordered_set<char> set = { 'a', 'b', 'c' };
				if (s[i] == '?') {
					if (i == 0) { // ?...
						if (set.count(s[i + 1])) set.erase(s[i + 1]); // Remove founds
						s[i] = *set.begin();
					}
					else if (i == s.size() - 1) {
						if (set.count(s[i - 1])) set.erase(s[i - 1]);
						s[i] = *set.begin();
					}
					else { // ..?..
						if (set.count(s[i + 1])) set.erase(s[i + 1]);
						if (set.count(s[i - 1])) set.erase(s[i - 1]);
						s[i] = *set.begin();
					}
				}
			}
			cout << s + "\n";
		}
	}
	return 0;
}