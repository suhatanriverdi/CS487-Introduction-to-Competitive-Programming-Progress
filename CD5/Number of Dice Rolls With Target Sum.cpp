// Question Link ---> https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        if (target > d * f) {
            return 0;
        }
        if (d == 1) {
            return (target > f ? 0 : 1);
        }
        map<pair<int, int>, int> dp; // {{remDices, num}, val}
        return rollDice(d, f, target, dp);
    }

    long long int rollDice(int d, int &f, int curSum, map<pair<int, int>, int> &dp) {
        if (dp.count({d, curSum})) {
            return dp[{d, curSum}];
        }  
        if (d == 1) {
            return (curSum > 0 && f >= curSum ? 1 : 0);
        }
        long long int res = 0;
        for (int i = 1; i <= f; i++) {
            res += rollDice(d - 1, f, curSum - i, dp);
            res = res % 1000000007;
        }
        dp[{d, curSum}] = res;
        return res;
    }
};