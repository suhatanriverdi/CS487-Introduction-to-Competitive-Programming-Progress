// Question Link ---> https://leetcode.com/problems/h-index-ii/
// Day #19
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) {
            return 0;
        }
        int L = 0, size = citations.size(), mid, R = size - 1;
        while (L <= R) {
            mid = (L + R) / 2;
            if (size - mid < citations[mid]) {
                R = mid - 1;
            } else if (size - mid > citations[mid]) {
                L = mid + 1;
            } else {
                return size - mid;
            }
        }
        return size - L;
    }
};