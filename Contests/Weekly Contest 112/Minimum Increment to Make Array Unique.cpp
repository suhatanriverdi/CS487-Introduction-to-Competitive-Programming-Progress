// Question Link ---> https://leetcode.com/problems/minimum-increment-to-make-array-unique/
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int res = 0, recent;
        sort(A.begin(), A.end());
        unordered_set<int> uniqs;
        for (int i = 0; i < A.size(); i++) {
            if (!uniqs.count(A[i])) {
                recent = A[i];
                uniqs.insert(A[i]);
            } else {
                recent++;
                uniqs.insert(recent);
                res += recent - A[i];
            }
        }
        return res;
    }
};