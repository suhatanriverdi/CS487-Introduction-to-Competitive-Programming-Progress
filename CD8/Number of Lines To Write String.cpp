// Question Link ---> https://leetcode.com/problems/number-of-lines-to-write-string/
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lineCnt = 0, curSum = 0, lastLineSize = 0;
        for (int i = 0; i < S.size(); i++) {
            if (curSum < 100) {
                curSum += widths[S[i] - 'a'];
            } 
            if (curSum == 100) {
                lineCnt++;
                curSum = 0;
            }
            if (curSum > 100) {
                lineCnt++;
                curSum = 0;
                curSum += widths[S[i] - 'a'];
                cout << curSum << endl;
            }
        }
        return {(curSum > 0 ? lineCnt + 1 : lineCnt), curSum};
    }
};