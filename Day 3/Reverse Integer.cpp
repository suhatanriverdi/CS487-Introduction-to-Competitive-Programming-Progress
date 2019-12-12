// Question Link ---> https://leetcode.com/problems/reverse-integer
// Day #3
//integer = 16 bit
//long long = at least 32 bit
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x >= INT_MAX || x <= INT_MIN) return 0; // Overflow
        bool isNegative = false;
        if (x < 0) {
            x *= (-1);
            isNegative = true;
        }
        long long sum = 0;
        bool once = true;
        int size = to_string(x).length() - 1;
        int remain;
        while (x > 0){
            remain = x % 10;
            if (remain != 0) sum += remain * pow(10, size);
            size--;
            x /= 10;
        }
        if (sum > INT_MAX) sum = 0;
        if (isNegative) return sum*= (-1);
        return sum;
    }
};

int main(void) {
	int x = 1534236469;
	Solution obj;
	cout << "old: " << x << endl << endl;
	cout << "reversed: " << obj.reverse(x);	
	return 0;
}
