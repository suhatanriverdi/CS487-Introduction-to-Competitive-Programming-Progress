// Question Link ---> https://leetcode.com/problems/jump-game-iii/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int, int>> states; // {index, val}
        states.push({start, arr[start]});
        arr[start] = -1; // Mark as visited
        int size = arr.size();
        while (!states.empty()) {
            auto cur = states.front(); states.pop();
            int rightJump = cur.second + cur.first;
            int leftJump = cur.first - cur.second;
            if (cur.second == 0) {
                return true;
            }
            if (rightJump < size && arr[rightJump] >= 0) {
                states.push({rightJump, arr[rightJump]});
                arr[rightJump] = -1;
            }
            if (leftJump >= 0 && arr[leftJump] >= 0) {
                states.push({leftJump, arr[leftJump]});
                arr[leftJump] = -1;
            }
        }
        return false;
    }
};