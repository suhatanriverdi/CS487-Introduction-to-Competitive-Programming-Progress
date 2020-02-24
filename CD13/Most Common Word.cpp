// Question Link ---> https://leetcode.com/problems/most-common-word/
class Solution {
public:
    string findMaxFreq(unordered_map<string, int> &wordFreqs) {
        int maX = 0;
        string ans = "";
        for (auto pair : wordFreqs) {
            if (pair.second > maX) {
                maX = pair.second;
                ans = pair.first;
            }
        }
        return ans;
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> wordFreqs;
        unordered_set<char> puncs = {'!', '?', '\'', ',', ';', '.', ' '};
        unordered_set<string> bannedWords;
        for (auto banWord : banned) {
            bannedWords.insert(banWord);
        }
        for (int i = 0; i < paragraph.size(); i++) {
            string tmp = "";
            while (i < paragraph.size() && !puncs.count(paragraph[i])) {
                tmp += paragraph[i];
                i++;
            }
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            if (!bannedWords.count(tmp) && tmp != "") {
                wordFreqs[tmp]++;
            }
        }
        return findMaxFreq(wordFreqs);
    }
};