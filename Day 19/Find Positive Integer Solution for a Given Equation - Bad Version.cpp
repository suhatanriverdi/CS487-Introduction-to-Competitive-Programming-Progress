// Question Link ---> https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
// Day #19
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        vector<vector<int>> posIntPairs;
        for (int i = 1; i <= 1000; i++) {
            for (int j = 1; j <= 1000; j++) {
                if (customfunction.f(i, j) == z) {
                    posIntPairs.push_back({i, j});
                }
            }           
        }
        return posIntPairs;
    }
};