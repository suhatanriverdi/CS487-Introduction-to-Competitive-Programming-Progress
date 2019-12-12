// Day #2
// Print Sum of Two Big Numbers
// Where,  -10^1000000 <= a,b <= 10^1000000
// Print a + b
// ASCII Table 0 -> 48
// 			   9 -> 57
// To find 6 -> 54('6') - 48 ('0') = 6
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isNegative(string num) {
		return (num[0] == '-' ? true : false);
	}

	char getBiggerNum(string a, string b) {
		int curA = 0, curB = 0;
		if (a.size() > b.size()) return 'a'; // a > b
		else if (a.size() == b.size()) { // a == b
			for (int i = 0, j = 0; i < a.size(); i++, j++) {
				curA = a[i] - '0';
				curB = b[j] - '0';
				if (curA > curB) return 'a';
				else if (curB > curA) return 'b';
			}
			return '0'; // if both nums are equal like 999 = 999
		}
		else return 'b'; // b > a
	}

	void getDecimal(string& bigger, int currentIndex) {
		int whereLeft = 0;
		for (int i = currentIndex - 1; i >= 0; i--) {
			int curValue = bigger[i] - '0';
			if (curValue > 0) { // The Closest Decimal Found
				curValue--; // ...02001 -> ...01001
				bigger[i] = curValue + '0';
				whereLeft = i;
				break;
			}
		}
		for (int j = whereLeft + 1; j < currentIndex; j++) bigger[j] = '9'; // ...01001 -> ...01991
	}

	void calculateSum(string a, string b) {
		string res = "", bigger = "", smaller = "";
		char negativeOne = '\0', big = '\0';
		if (a == "0" || b == "0") { cout << (a == "0" ? b : a) << endl; return; }
		if ((isNegative(a) && isNegative(b)) || (!isNegative(a) && !isNegative(b))) sumTwoBigNumbers(a, b);
		else { 
			isNegative(a) ? negativeOne = 'a' : negativeOne = 'b'; // Save negative one
			isNegative(a) ? a.erase(0, 1) : b.erase(0, 1); // Then, remove "-" sign
			if (getBiggerNum(a, b) == 'a') { bigger = a; big = 'a'; smaller = b; }
			if (getBiggerNum(a, b) == 'b') { bigger = b; big = 'b'; smaller = a; }
			if (getBiggerNum(a, b) == '0') { cout << "Result: 0\n"; return; }
			int bigCur, smallCur;
			for (int i = bigger.size() - 1, j = smaller.size() - 1; i >= 0 || j >= 0; i--, j--) {
				if (i < 0) bigCur = 0; else bigCur = bigger[i] - '0';
				if (j < 0) smallCur = 0; else smallCur = smaller[j] - '0';
				if (smallCur > bigCur) { // need to call getDecimal
					getDecimal(bigger, i);
					bigCur += 10;
					res += (bigCur - smallCur) + '0';
				}
				else res += (bigCur - smallCur) + '0';
			}
			cout << "Result: ";
			if (big == negativeOne) cout << "-";
			int numStarts = 0;
			for (numStarts = res.size() - 1; numStarts >= 0; numStarts--) if (res[numStarts] != '0') break;
			for (int i = numStarts; i >= 0; i--) cout << res[i];
		}
	}

	void sumTwoBigNumbers(string a, string b) {
		string res = "";
		bool bothNegative = false;
		if ((isNegative(a) && isNegative(b))) {
			a.erase(0, 1);
			b.erase(0, 1);
			bothNegative = true;
		}

		int curIntA, curIntB, carry = 0;
		for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
			if (i < 0) curIntA = 0; else curIntA = a[i] - '0';
			if (j < 0) curIntB = 0; else curIntB = b[j] - '0';
			if (carry > 0) {
				res += ((curIntA + curIntB + carry) % 10) + '0';
				carry = (curIntA + curIntB + carry) / 10;
			}
			else {
				res += ((curIntA + curIntB) % 10) + '0';
				carry = (curIntA + curIntB) / 10;
			}
		}

		if (carry) res += '1';
		if (bothNegative) cout << "-";
		for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
	}
};

int main(void) {
	Solution obj;
	string a, b;
	cin >> a >> b;
	obj.calculateSum(a, b);
	return 0;
}