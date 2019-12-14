// Question Link ---> https://codeforces.com/problemset/problem/4/A
// Day #3
#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	if (n % 2 == 0 && n != 2) cout << "YES";
	else cout << "NO";
	return 0;
}