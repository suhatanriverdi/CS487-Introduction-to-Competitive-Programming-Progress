// Question Link ---> https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    	int negativeCount = 0;
        for (auto row : grid) {
        	for (int i = row.size() - 1; i >= 0 && row[i] < 0; i--) {
        		negativeCount++;
        	}
        }
        return negativeCount;
    }
};