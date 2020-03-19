// Question Link ---> https://leetcode.com/problems/bulb-switcher-iii/
class Solution {
public:
    int numTimesAllBlue(vector<int> &light) {
        int rIdx = 0, cnt = 0, openCnt = 0;
        for (int i = 0; i < light.size(); i++) {
            openCnt++;
            rIdx = max(rIdx, light[i]);
            if (openCnt == rIdx) {
                cnt++;
            }
        }
        return cnt;
    }
};