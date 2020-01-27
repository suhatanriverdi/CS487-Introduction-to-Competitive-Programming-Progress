// Question Link ---> https://leetcode.com/problems/as-far-from-land-as-possible/
// Day #25
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int M = grid.size(), maxDistance = 0;
        queue<pair<int, int>> lands;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    lands.push({i, j});
                }
            }
        }
        bfs(grid, lands, maxDistance);
        return maxDistance - 1;
    }
    
    void bfs(vector<vector<int>> &grid, queue<pair<int, int>> &lands, int &maxDistance) {
        while (!lands.empty()) {
            auto curLand = lands.front();
            lands.pop();
            pair<int, int> directions[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
            for (auto dir : directions) {
                int nx = curLand.first + dir.first;
                int ny = curLand.second + dir.second;
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size() && grid[nx][ny] == 0) {
                    lands.push({nx, ny});
                    grid[nx][ny] = grid[curLand.first][curLand.second] + 1;
                    maxDistance = max(maxDistance, grid[nx][ny]);
                }
            }
        }
    }
};