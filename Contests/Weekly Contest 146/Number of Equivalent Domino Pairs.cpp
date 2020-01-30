// Question Link ---> https://leetcode.com/problems/number-of-equivalent-domino-pairs/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt = 0;
        map<pair<int, int>, int> m, equ;
        unordered_set<int> s;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i][0] != dominoes[i][1]) {
                m[{dominoes[i][0], dominoes[i][1]}]++;
                m[{dominoes[i][1], dominoes[i][0]}]++;
            } else {
                equ[{dominoes[i][1], dominoes[i][0]}]++;
            }
        }
        for (auto i : m) {
            if (i.second > 1) {
                if (!s.count(i.second)) {
                    s.insert(i.second);
                    cnt += ((i.second * (i.second - 1)) / 2);
                }
                else {
                    s.erase(i.second); 
                }
            }
        }
        for (auto i : equ) {
            if (i.second > 1) {
                cnt += ((i.second * (i.second - 1)) / 2);
            }
        }
        return cnt;
    }
};