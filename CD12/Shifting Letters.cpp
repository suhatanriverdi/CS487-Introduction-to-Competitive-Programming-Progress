// Question Link ---> https://leetcode.com/problems/shifting-letters/
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int size = S.size();
        vector<long long int> dp(size, 0);
        for (int i = 0; i < size; i++) {
            dp[i] = shifts[i];
        }
        for (int i = size - 2; i >= 0; i--) {
            dp[i] += dp[i + 1];
        }
        for (int i = 0; i < size; i++) {
            int shiftAmount = dp[i] % 26;
            while (shiftAmount-- > 0) {
                if (S[i] == 122) {
                    S[i] = 97;
                } else {
                    S[i]++;
                }
            }
        }
        return S;
    }
};