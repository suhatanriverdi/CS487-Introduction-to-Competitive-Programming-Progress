// Question Link ---> https://leetcode.com/problems/maximum-length-of-pair-chain/
class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int cnt = 0, prev = INT_MIN;
        sort(pairs.begin(), pairs.end(), cmp);
        for (int i = 0; i < pairs.size(); i++) {
            if (prev < pairs[i][0]) {
                prev = pairs[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};