// Question Link ---> https://leetcode.com/problems/first-bad-version/
// Day #19
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while (L < R) {
            int mid = L + (R - L) / 2;
            if (isBadVersion(mid)) R = mid;
            else L = mid + 1;
        }
        return L;
    }
};