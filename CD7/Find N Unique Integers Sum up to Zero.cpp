// Question Link ---> https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int until = n/2;
        if (n & 1) { // Odd
            res.push_back(0);
        }
        for (int i = 1; i <= until; i++) { res.push_back(i); res.push_back(-i); }   
        return res;
    }
};