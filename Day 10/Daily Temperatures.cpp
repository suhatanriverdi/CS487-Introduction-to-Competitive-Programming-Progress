//Question Link ---> https://leetcode.com/problems/daily-temperatures/
// Day #10
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> future(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            int curMax = T[i];
            for (int j = i + 1; j < T.size(); j++) {
                if (T[j] > curMax) {
                    future[i] = abs(j - i);
                    break;
                }
            }    
        }
        return future;
    }
};