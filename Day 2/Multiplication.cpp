// Day #2
// Print Multiplication of Two Big Numbers
// Where,  0 <= a,b <= 10^1000000
// Print a * b
// ASCII Table 0 -> 48
// 			   9 -> 57
// To find 6 -> 54('6') - 48 ('0') = 6
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string sumTwoBigNumbers(string a, string b) {
		if (a[0] == '0' || b[0] == '0') return (a[0] == '0' ? b : a);
		string res(a.size() > b.size() ? a.size() : b.size(), '\0');
		int curIntA, curIntB, carry = 0;
		int i = (a.size() > b.size() ? (a.size() - 1) : (b.size() - 1)); // Bigger
		int j = (a.size() > b.size() ? (b.size() - 1) : (a.size() - 1));
		string big = (a.size() > b.size() ? a : b);
		string small = (a.size() > b.size() ? b : a);
		for (; i >= 0 || j >= 0; i--, j--) {
			if (i < 0) curIntA = 0; else curIntA = big[i] - '0';
			if (j < 0) curIntB = 0; else curIntB = small[j] - '0';
			if (carry > 0) {
				res[i] = ((curIntA + curIntB + carry) % 10) + '0';
				carry = (curIntA + curIntB + carry) / 10;
			}
			else {
				res[i] = ((curIntA + curIntB) % 10) + '0';
				carry = (curIntA + curIntB) / 10;
			}
		}
		if (carry == 1) return "1" + res;
		return res;
	}

	void multiplyTwoBigNumbers(string a, string b) {
		if (a[0] == '0' || b[0] == '0') { cout << "0"; return; }
		if (a == "1" || b == "1") { cout << (a == "1" ? b : a); return; };
		if ((!isNegative(a) && !isNegative(b)) || (isNegative(a) && isNegative(b))) checkNegativity(a, b, false);
		else checkNegativity(a, b, true);
	}

	void checkNegativity(string a, string b, bool negativeResult) {
		if (!negativeResult) { // + +   - - 
			if ((isNegative(a) && isNegative(b))) {
				a.erase(0, 1);
				b.erase(0, 1);
			}
		}
		else { // + -
			if ((isNegative(a))) a.erase(0, 1);
			else b.erase(0, 1);
		}
		int curA, curB, carry = 0, mulRes = 0;
		vector<string> numsToBeAdded;
		for (int i = a.size() - 1; i >= 0; i--) {
			string tempSum(b.size(), '\0');
			curA = a[i] - '0'; // Convert char to Int
			for (int j = b.size() - 1; j >= 0; j--) {
				curB = b[j] - '0'; // Convert char to Int
				mulRes = (curA * curB) + carry;
				tempSum[j] = (mulRes % 10) + '0'; // Convert Int to Char
				carry = mulRes / 10;
			}
			if (carry > 0) {
				string carryStr(1, carry + '0');
				carryStr += tempSum;
				numsToBeAdded.push_back(carryStr);
				carry = 0;
			}
			else numsToBeAdded.push_back(tempSum);
		}
		for (int i = 0; i < numsToBeAdded.size(); i++) { // Add Zeros at the end of strings for addition
			int zeroLeft = i;
			while (zeroLeft--) numsToBeAdded[i].append("0");
		}
		for (auto s : numsToBeAdded) cout << s << endl;
		cout << endl << endl; 
		if (numsToBeAdded.size() == 1) cout << "Result: " << (negativeResult == true ? "-" : "") << numsToBeAdded[0] << endl;
		else {
			string ret = "0";
			for (int i = 0; i < numsToBeAdded.size(); i++) {
				ret = sumTwoBigNumbers(ret, numsToBeAdded[i]);
			}
			cout << "Result: " << (negativeResult == true ? "-" : "") << ret << endl;
		}
	}

	bool isNegative(string num) {
		return (num[0] == '-' ? true : false);
	}
};

int main(void) {
	string a, b;
	cin >> a >> b;
	Solution obj;
	obj.multiplyTwoBigNumbers(a, b);
	return 0;
}