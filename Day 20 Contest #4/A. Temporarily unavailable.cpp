// Question Link ---> https://codeforces.com/contest/1282/problem/A
﻿// Day #20 #Contest 4
#include <iostream>
#include <vector>
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	long long int a, b, c, r; // start, end, base, range
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> r;
		long long int L = c - r, R = c + r;
		long long int big = (a > b) ? a : b;
		long long int small = (a > b) ? b : a;
		if ((big <= R && big >= L) && (small >= L && small <= R)) { cout << "0\n"; continue; }
		else { // Exact answer
			if ((big < L && small < L) || (big > R && small > R)) { // b a .. || .. b a
				cout << abs(big - small) << "\n";
			}
			else if (small < L && big > R) { // b .. a
				cout << abs(big - R) + abs(small - L) << "\n";
			}
			else if ((small <= R && small >= L) && big > R) { // b .. a
				cout << abs(big - R) << "\n";
			}
			else if (small < L && (big <= R && big >= L)) { // b .. a
				cout << abs(small - L) << "\n";
			}
		}
	}
	return 0;
}