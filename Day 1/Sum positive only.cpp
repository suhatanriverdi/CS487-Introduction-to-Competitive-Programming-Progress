#include <iostream>
#include <vector>
using namespace std;
// Day #1
// Print Sum of Two Big Numbers
// Where,  0 <= a,b <= 10^1000000
// Print a + b
// ASCII Table 0 -> 48
// 			   9 -> 57
// To find 6 -> 54('6') - 48 ('0') = 6

class Solution {
public:
	void sumTwoBigNumbers(string a, string b) {
		string res = "";
		int curIntA, curIntB, carry = 0;
		for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
			if (i < 0) curIntA = 0; else curIntA = a[i] - '0';
			if (j < 0) curIntB = 0; else curIntB = b[j] - '0';
			if (carry > 0)  {
				res += ((curIntA + curIntB + carry) % 10) + '0';
				carry = (curIntA + curIntB + carry) / 10;
			}
			else {
				res += ((curIntA + curIntB) % 10) + '0';
				carry = (curIntA + curIntB) / 10;
			}
		}
		if (carry) res += '1';
		for (int i = res.size(); i >= 0; i--) cout << res[i];
	}
};

int main(void) {
	string a, b;
	cin >> a >> b;
	Solution obj;
	obj.sumTwoBigNumbers(a, b);
	return 0;
}