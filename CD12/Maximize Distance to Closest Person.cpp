// Question Link ---> https://leetcode.com/problems/maximize-distance-to-closest-person/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        queue<int> onesQueue;
        int size = seats.size(), maxDist = 1;
        for (int i = 0; i < size; i++) {
            if (seats[i] == 1) {
                onesQueue.push(i);
            }
        }
        while(!onesQueue.empty()) {
            int cur = onesQueue.front();
            onesQueue.pop();
            if (cur + 1 < size && seats[cur + 1] == 0) {
                onesQueue.push(cur + 1);
                seats[cur + 1] = seats[cur] + 1;
                maxDist = max(maxDist, seats[cur + 1]);
            }
            if (cur - 1 >= 0 && seats[cur - 1] == 0) {
                onesQueue.push(cur - 1);
                seats[cur - 1] = seats[cur] + 1;
                maxDist = max(maxDist, seats[cur - 1]);
            }
        }
        return maxDist - 1;
    }
};