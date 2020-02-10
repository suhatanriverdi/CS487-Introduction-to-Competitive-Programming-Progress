// Question Link ---> https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int M = s.size();
        vector<vector<int>> dp(M, vector(M, 0));
        for (int i = 0; i < M; i++) {
            dp[i][i] = 1;
        }
        for (int curLen = 1; curLen < M; curLen++) {
            for (int i = 0; i + curLen < M; i++) {
                if (s[i] == s[i + curLen]) {
                    dp[i][i + curLen] = 2 + dp[i + 1][i + curLen - 1];
                } else {
                    dp[i][i + curLen] = max(dp[i][i + curLen - 1], dp[i + 1][i + curLen]);
                }
            }
        }
        return dp[0][M - 1];
    }
};