// Question Link ---> https://leetcode.com/problems/n-th-tribonacci-number/
// Day #16
class Solution {
public:
    int tribonacci(int n, int a = 0, int b = 1, int c = 1) {
        if (n <= 1) return n;
        if (n == 2) return c;
        return tribonacci(n - 1, b, c, a + b + c);
    }
};