// Question Link ---> https://leetcode.com/problems/monotonic-array/
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() == 1) {
            return true;
        }
        if (isIncreasing(A)) {
            return true;
        }
        if (isDecreasing(A)) {
            return true;
        }
        return false;
    }
    
    bool isIncreasing(vector<int> &A) {
        for (int i = 0; i + 1 < A.size(); i++) {
            if (A[i] > A[i + 1]) {
                return false;  
            }
        }
        return true;
    }
    
    bool isDecreasing(vector<int> &A) {
        for (int i = 0; i + 1 < A.size(); i++) {
            if (A[i] < A[i + 1]) {
                return false;  
            }
        }
        return true;
    }
};