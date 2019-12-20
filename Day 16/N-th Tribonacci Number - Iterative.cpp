// Question Link ---> https://leetcode.com/problems/n-th-tribonacci-number/
// Day #16
class Solution {
public:
    int tribonacci(int n) {
        vector<long long int> v = { 0, 1, 1, 2 };
        if (n < 4) return v[n];
        for (int i = 0; i < n; i++) v.push_back(v[i + 3] + v[i + 2] + v[i + 1]);
        return v[n];
    }
};