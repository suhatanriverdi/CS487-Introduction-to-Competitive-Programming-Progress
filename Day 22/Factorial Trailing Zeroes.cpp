// Question Link ---> https://leetcode.com/problems/factorial-trailing-zeroes/
// Day #22
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += n / 5;
            n = n / 5;
        }
        return cnt;
    }
};