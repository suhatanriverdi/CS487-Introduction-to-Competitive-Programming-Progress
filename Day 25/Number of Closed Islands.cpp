// Question Link ---> https://leetcode.com/problems/number-of-closed-islands/
// Day #25
class Solution {
public:
	int closedIsland(vector<vector<int>>& grid) {
		int numOfClosedIslands = 0;
		// Exclude if there exists any island(s) touching corners
		// Look for Upper and Bottom Edge
		for (int i = 0; i < grid[0].size(); i++) {
			if (grid[0][i] == 0) {
				dfs(grid, 0, i);
			}
			if (grid[grid.size() - 1][i] == 0) {
				dfs(grid, grid.size() - 1, i);
			}
		}
		// Look for Left and Right Edge
		for (int j = 0; j < grid.size(); j++) {
			if (grid[j][0] == 0) {
				dfs(grid, j, 0);
			}
			if (grid[j][grid[0].size() - 1] == 0) {
				dfs(grid, j, grid[0].size() - 1);
			}
		}
		// Find number of connected Lands
		for (int i = 1; i < grid.size(); i++) {
			for (int j = 1; j < grid[i].size(); j++) {
				if (grid[i][j] == 0) { // If any land inside, run dfs
					numOfClosedIslands++;
					dfs(grid, i, j);
				}
			}
		}
		return numOfClosedIslands;
	}

	void dfs(vector<vector<int>>& grid, int x, int y) {
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0) {
			grid[x][y] = -1;
			dfs(grid, x, y + 1); // Right
			dfs(grid, x, y - 1); // Left
			dfs(grid, x + 1, y); // Up
			dfs(grid, x - 1, y); // Down
		}
	}
};