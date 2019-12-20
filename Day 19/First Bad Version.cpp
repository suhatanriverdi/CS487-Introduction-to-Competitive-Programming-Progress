// Question Link ---> https://leetcode.com/problems/first-bad-version/
// Day #19
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = n;
        for (; i >= 0 && isBadVersion(i); i--);
        return i + 1;
    }
};