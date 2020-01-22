// Question Link ---> https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
// Day #19
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        vector<vector<int>> res;
        for (int i = 1; i <= 1000; i++) {
            int left = 1, right = 1000, mid;
            while (left <= right) {
                mid = (left + right) / 2;
                int returnedVal = customfunction.f(i, mid);
                if (returnedVal == z) {
                    res.push_back({i, mid});
                    break;
                }
                if (returnedVal > z) {
                    right = mid - 1;
                } 
                else {
                    left = mid + 1;
                }
            }
        }
        return res;
    }
};
