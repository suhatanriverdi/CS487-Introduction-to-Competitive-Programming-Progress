// Question Link ---> http://codeforces.com/contest/1278/problem/A
// Educational Codeforces Round 78 (Rated for Div. 2)
// Day #18 #Contest 3
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	string p, h;
	cin >> T;
	while (T--) {
		cin >> p >> h;
		if (h.size() < p.size()) { cout << "NO\n"; }
		else {
			bool found = false;
			unordered_map<char, int> freq;
			for (int i = 0; i < p.size(); i++) freq[p[i]]++;
			for (int i = 0; i + (p.size() - 1) < h.size(); i++) {
				unordered_map<char, int> tmp;
				for (int j = i, t = p.size(); t > 0 && j < h.size(); j++, t--) tmp[h[j]]++;
				if (freq == tmp) {
					found = true;
					cout << "YES\n";
					break;
				}
			}
			if (!found) cout << "NO\n";
		}
	}
	return 0;
}