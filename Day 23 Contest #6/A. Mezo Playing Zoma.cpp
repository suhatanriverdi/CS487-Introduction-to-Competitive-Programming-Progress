// Question Link ---> https://codeforces.com/contest/1282/problem/A
﻿// Day #23 #Contest 6
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, L = 0, R = 0;
	cin >> n;
	vector<char> s(n);
	for (int i = 0; i < n; i++) { 
		cin >> s[i]; 
		if (s[i] == 'L') L++; else R++;
	}
	cout << L + R + 1;
	return 0;
}