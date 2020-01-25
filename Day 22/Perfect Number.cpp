// Question Link ---> https://leetcode.com/problems/perfect-number/
// Day #22
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 5 || num % 2 != 0) {
            return false;
        }
        int sum = 1;
        int size = (num % 2 == 0 ? 0 : num % 2) + (num / 2);
        for (int i = 2; i <= size; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        return (sum == num);
    }
};