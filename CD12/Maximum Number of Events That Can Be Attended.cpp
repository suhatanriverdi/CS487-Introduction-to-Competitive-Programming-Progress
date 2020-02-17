// Question Link ---> https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    int maxEvents(vector<vector<int>>& events) {
        unordered_set<int> attended;
        sort(events.begin(), events.end(), cmp);
        for (auto event : events) {
            for (int i = event[0]; i <= event[1]; i++) {
                if (!attended.count(i)) {
                    attended.insert(i);
                    break;
                }
            }
        }
        return attended.size();
    }
};