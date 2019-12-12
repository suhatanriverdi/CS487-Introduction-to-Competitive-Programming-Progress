// Codeforces Codeforces Round #604 (Div. 2)
// Question Link ---> https://codeforces.com/contest/1265/problem/A
// Day #13 #Contest 1
#include <iostream>
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
				if (s[i] == '?') {
					if (i == 0) { // ?...
						if (s[i + 1] == '?') s[i] = 'a'; // ??...
						else if (s[i + 1] == 'a') s[i] = 'b'; // ?a...
						else if (s[i + 1] == 'b') s[i] = 'a'; // ?b...
						else s[i] = 'a'; // ?c...
					}
					else if (i == s.size() - 1) { // ...?
						if (s[i - 1] == '?') s[i] = 'a'; // ??...
						else if (s[i - 1] == 'a') s[i] = 'b'; // ?a...
						else if (s[i - 1] == 'b') s[i] = 'a'; // ?b...
						else s[i] = 'a'; // ?c...
					}
					else { // ..?..
						if (s[i - 1] == 'a') { // ..a?..
							if (s[i + 1] == '?') s[i] = 'b'; // ..a??..
							else if (s[i + 1] == 'a') s[i] = 'b'; // ..a?a..
							else if (s[i + 1] == 'b') s[i] = 'c'; // ..a?b..
							else s[i] = 'b'; // ..a?c..
						}
						if (s[i - 1] == 'b') { // ..b?..
							if (s[i + 1] == '?') s[i] = 'a'; // ..b??..
							else if (s[i + 1] == 'a') s[i] = 'c'; // ..b?a..
							else if (s[i + 1] == 'b') s[i] = 'a'; // ..b?b..
							else s[i] = 'a'; // ..b?c..
						}
						if (s[i - 1] == 'c') { // ..c?..
							if (s[i + 1] == '?') s[i] = 'a'; // ..c??..
							else if (s[i + 1] == 'a') s[i] = 'b'; // ..c?a..
							else if (s[i + 1] == 'b') s[i] = 'a'; // ..c?b..
							else s[i] = 'a'; // ..c?c..
						}
					}
				}
			}
			cout << s + "\n";
		}
	}
	return 0;
}