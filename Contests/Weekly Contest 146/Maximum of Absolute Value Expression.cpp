// Question Link ---> https://leetcode.com/problems/maximum-of-absolute-value-expression/
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        res = max(loopOver(1, 1, arr1, arr2), res);
        res = max(loopOver(-1, -1, arr1, arr2), res);
        res = max(loopOver(1, -1, arr1, arr2), res);
        res = max(loopOver(-1, 1, arr1, arr2), res);
        return res;
    }
    
    int loopOver(int s1, int s2, vector<int>& arr1, vector<int>& arr2) {
        int maX = INT_MIN, miN = INT_MAX;
        for (int i = 0; i < arr1.size(); i++) {
            maX = max(maX, s1 * arr1[i] + s2 * arr2[i] + i);
            miN = min(miN, s1 * arr1[i] + s2 * arr2[i] + i);
        }
        return maX - miN;
    }
};