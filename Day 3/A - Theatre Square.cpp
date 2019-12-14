// Question Link ---> https://codeforces.com/problemset/problem/1/A
// Day #3
#include <iostream>    
using namespace std;

int main(void) {
	int m, n, a;
	long long width=0, height=0;
	cin >> m >> n >> a;
	if (m % a == 0) width = m/a;
	else width=(m/a+1);
	if (n %a  == 0) height = n/a;
	else height=(n/a+1);
	cout << width*height << endl;
	return 0;
}