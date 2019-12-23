// Calculator
// Day #4
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void calculator() {
	string n1, opt, n2;
	cout << "Enter number, an operation and number (1 / 8): ";
	cin >> n1 >> opt >> n2;
	double a = stod(n1), b = stod(n2), result = 0;
	if (opt == "/") {
		cout << a / b << endl;
	}
	else if (opt == "*") {
		cout << a * b << endl;
	}
	else if (opt == "+" || opt == "-") {
		cout << a + b << endl;
	}
}

int main(void) {
	calculator();
	return 0;
}