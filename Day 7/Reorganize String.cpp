// Question Link ---> https://leetcode.com/problems/reorganize-string/
// Day #7
class Solution {
public:
    string reorganizeString(string S) {
        if (S.size() == 1) return S;
        string res = "";
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> freq;
        for (auto c : S) m[c]++;
        for (auto i : m) freq.push({ i.second, i.first });
        while (!freq.empty()) {
            auto curr = freq.top();
            freq.pop();
            if (freq.empty()) {
                if (curr.first > 1) return "";
                else res += curr.second;
                break;
            }
            auto curr2 = freq.top();
            freq.pop();
            res += curr.second; res += curr2.second;
            curr.first--; curr2.first--;
            if (curr.first > 0)  freq.push({ curr.first, curr.second });
            if (curr2.first > 0)  freq.push({ curr2.first, curr2.second });
        }
        return res;
    }
};