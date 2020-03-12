// Question Link ---> https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
class Solution {
public:
    string generateTheString(int n) {
        string res(n,'a');
        if (n & 1) { // If the number is odd
            return res;
        }
        // If the number is even
        res[n - 1] = 'b';
        return res;
    }
};