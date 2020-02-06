// Question Link ---> https://leetcode.com/problems/jump-game-v/
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int res = 1;
        vector<int> dp(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            res = max(res, runJump(arr, d, i, dp));
        }
        return res;
    }
    
    int runJump(vector<int> &arr, int &d, int cur, vector<int> &dp) {
        if (dp[cur] > 0) {
            return dp[cur];
        }
        int res = 1;
        for (int i = cur + 1, k = d; i < arr.size() && k && arr[i] < arr[cur]; i++, k--) { // Try jumping to Right
            res = max(runJump(arr, d, i, dp) + 1, res);
        }
        for (int i = cur - 1, k = d; i >= 0 && k && arr[i] < arr[cur]; i--, k--) { // Try jumping to Left
            res = max(runJump(arr, d, i, dp) + 1, res);
        }
        return dp[cur] = res;
    }
};