// Question Link ---> https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }
        for (int i = 2; i < cost.size(); i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        int size = cost.size() - 1;
        return min(cost[size], cost[size - 1]);
    }
};