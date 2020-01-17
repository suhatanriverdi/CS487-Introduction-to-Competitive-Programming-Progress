//Question Link ---> https://leetcode.com/problems/car-fleet/submissions/
// Day #11

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> m; // {position, arrivalTime}
        for (int i = 0; i < speed.size(); i++) m.insert({ position[i], (target - position[i]) / double(speed[i]) });
        vector<double> v = {-1};
        int cnt = 0;
        for (auto it = m.begin(); it != m.end(); it++) if (v[v.size() - 1] != it->second) v.push_back((double)it->second);
        for (int i = 1; i < v.size(); i++) {
            double idx, mx = v[i]; // If any greater found, save its index
            bool found = false;
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j] > mx) {
                    idx = j;
                    mx = v[j];
                    found = true;
                }
            }
            if (found) i = idx;
            cnt++;
        }
        return cnt;
    }
};