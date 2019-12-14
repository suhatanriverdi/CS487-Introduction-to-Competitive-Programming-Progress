// Question Link ---> https://codeforces.com/contest/1272/problem/C
// Codeforces Round #605 (Div. 3)
// Day #17 #Contest 2
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unordered_set<char> ks;
	vector<long long int> seqs;
	int n, k; string s; char tmp;
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < k; i++) { cin >> tmp; ks.insert(tmp); }
	for (int i = 0; i < n; i++) {
		int setSize = 0;
		while (ks.count(s[i])) {
			setSize++;
			i++;
		}
		if (setSize) seqs.push_back(setSize);
	}
	if (seqs.size() == 0) cout << "0";
	else {
		long long int sum = 0;
		for (auto i : seqs) sum += (i * (i + 1)) / 2;
		cout << sum;
	}
	return 0;
}