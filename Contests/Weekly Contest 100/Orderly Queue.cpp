// Question Link ---> https://leetcode.com/problems/orderly-queue/
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K == 1) {
            string curNewStr = getMovedStr(S);
            string minStr = min(curNewStr, S);
            while (curNewStr != S) {
                curNewStr = getMovedStr(curNewStr);
                minStr = min(curNewStr, minStr);
            }
            return minStr;
        }
        sort(S.begin(), S.end());
        return S;
    }
    
    string getMovedStr(string &oldStr) {
        string newStr = "";
        for (int i = 1; i < oldStr.size(); i++) {
            newStr += oldStr[i];
        }
        newStr += oldStr[0];
        return newStr;
    }
};