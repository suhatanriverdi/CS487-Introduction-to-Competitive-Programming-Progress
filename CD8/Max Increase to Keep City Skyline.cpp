// Question Link ---> https://leetcode.com/problems/max-increase-to-keep-city-skyline/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        int maX2, maX;
        unordered_map<int, int> colMax, rowMax; // {idx, val}
        for (int i = 0; i < M; i++) {
            maX = maX2 = INT_MIN;
	        for (int j = 0; j < N; j++) {
	        	maX = max(maX, grid[i][j]);
                maX2 = max(maX2, grid[j][i]);
	        }
	        rowMax.insert({i, maX});
            colMax.insert({i, maX2});
        }
        int res = 0;
        for (int i = 0; i < M; i++) {
        	for (int j = 0; j < N; j++) {
        		res += min(rowMax[i], colMax[j]) - grid[i][j];
        	}
        }
        return res;
    }
};