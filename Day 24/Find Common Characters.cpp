// Question Link ---> https://leetcode.com/problems/find-common-characters/
// Day #24

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if (A.size() == 1) return A;
        unordered_map<char, int> main, temp;
        for (auto c : A[0]) main[c]++;
        for (auto s : main) cout << s.first << " " << s.second << endl; cout << endl << endl;
        for (int i = 1; i < A.size(); i++) {
            for (auto &c : A[i]) if (main[c]) { temp[c]++; main[c]--; } 
            main = temp;
            temp.clear();
        }
        vector<string> res; string tmp;
        for (auto s : main) while(s.second--) { tmp += s.first; res.push_back(tmp); tmp = ""; } 
        return res;
    }
};