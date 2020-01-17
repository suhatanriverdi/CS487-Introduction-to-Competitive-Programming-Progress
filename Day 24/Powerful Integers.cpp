// Question Link ---> https://leetcode.com/problems/powerful-integers/
// Day #24

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        vector<int> v;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                long long int temp = pow(x, i) + pow(y, j);
                if (temp > 0 && temp <= bound) {
                    s.insert(temp);
                }
            }
        }
        for (auto i : s) v.push_back(i);
        return v;
    }
};