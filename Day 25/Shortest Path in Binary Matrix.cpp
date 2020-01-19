// Question Link ---> https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Day #25
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        if (grid[0][0] != 0 || grid[M - 1][N - 1] != 0) {
            return -1;
        }
        queue<pair<int, int>> points;
        points.push({ 0, 0 });
        grid[0][0] = 1;
        while (!points.empty()) {
            pair<int, int> currrentCell = points.front();
            points.pop();
            if (currrentCell == make_pair(M - 1, N - 1)) {
                return grid[M - 1][N - 1];
            }
            pair<int, int> directions[8] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
            for (auto direction : directions) {
                int nX = currrentCell.first + direction.first;
                int nY = currrentCell.second + direction.second;
                if (nX >= 0 && nX < grid.size() && nY >= 0 && nY < grid[nX].size() && grid[nX][nY] == 0) {
                    points.push({ nX, nY });
                    grid[nX][nY] = grid[currrentCell.first][currrentCell.second] + 1;
                }
            }
        }
        return -1;
    }
};