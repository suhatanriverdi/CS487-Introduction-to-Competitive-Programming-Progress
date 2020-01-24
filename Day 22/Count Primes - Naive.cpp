// Question Link ---> https://leetcode.com/problems/count-primes/
// Day #22
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i) == true) {
                cnt++;
            } 
        }
        return cnt;
    }
    
    bool isPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};