// Question Link ---> https://leetcode.com/problems/bag-of-tokens/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end()); // 1 3 5
        bool playedFaceUp = true, playedFaceDown = true;
        int points = 0, maxIndex = tokens.size() - 1, minIndex = 0;
        while (minIndex <= maxIndex && P > 0 && (playedFaceUp || playedFaceDown)) {
            playedFaceUp = playedFaceDown = false;
            while (minIndex < tokens.size() && P >= tokens[minIndex]) {
                P -= tokens[minIndex++];
                points++;
                playedFaceUp = true;
            }
            if (maxIndex >= 0 && minIndex < maxIndex && points > 0) {
                P += tokens[maxIndex--];
                points--;
                playedFaceDown = true;
            }
        }
        return points;
    }
};