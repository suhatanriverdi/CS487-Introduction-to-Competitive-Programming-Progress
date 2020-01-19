// Question Link ---> https://leetcode.com/problems/rotting-oranges/
// Day #25
class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int lastestMinute = 0;
        int M = grid.size();
        int N = grid[0].size();
        queue<pair<int, int>> points;
        vector<vector<int>> visited(M, vector<int>(N, -1));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 2) {
                    points.push({ i, j });
                    visited[i][j] = 0;
                }
            }
        }
        bfs(grid, visited, lastestMinute, points);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return lastestMinute;
    }

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int &latestMinute, queue<pair<int, int>> &points) {
        while (!points.empty()) {
            pair<int, int> currentPoint = points.front();
            points.pop();
            pair<int, int> directions[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
            for (auto direction : directions) {
                int nX = currentPoint.first + direction.first;
                int nY = currentPoint.second + direction.second;
                if (nX >= 0 && nX < grid.size() && nY >= 0 && nY < grid[nX].size() && grid[nX][nY] == 1) {
                    grid[nX][nY] = 2;
                    points.push({ nX, nY });
                    int newMinute = visited[currentPoint.first][currentPoint.second] + 1;
                    visited[nX][nY] = newMinute;
                    latestMinute = max(newMinute, latestMinute);
                }
            }
        }
    }
};