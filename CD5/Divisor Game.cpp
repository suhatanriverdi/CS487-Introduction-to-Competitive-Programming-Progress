// Question Link ---> https://leetcode.com/problems/divisor-game/
class Solution {
public:
    bool divisorGame(int N) {
        return !(N & 1);
    }
};