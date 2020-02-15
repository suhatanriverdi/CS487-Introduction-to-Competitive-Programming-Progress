// Question Link ---> https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        vector<vector<long long int>> dp(M, vector<long long int>(N, 0));
        
        if (M == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[M - 1][N - 1] == 1) {
            return 0;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = obstacleGrid[i][j];
            }
        }

        for (int i = 0, hasObstacle = 0; i < N; i++) { // First Row
            if (dp[0][i] == 0 && !hasObstacle) {
                dp[0][i] = 1;
            } else {
                dp[0][i] = -1;
                hasObstacle = true;
            }
        }
        
        for (int i = 1, hasObstacle = 0; i < M; i++) { // First Column
            if (dp[i][0] == 0 && !hasObstacle) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = -1;
                hasObstacle = true;
            }
        }
        
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (dp[i][j] == 1) {
                    dp[i][j] = -1;
                } else {
                    long long int up = dp[i - 1][j];
                    long long int left = dp[i][j - 1];
                    if (up > 0 && left > 0) {
                        dp[i][j] += up + left;
                    } else {
                        dp[i][j] += max(up, left);
                    }
                }
            }
        }
        
        int res = dp[M - 1][N - 1];
        return (res > 0 ? res : 0);
    }
};
