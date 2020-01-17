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
                    if (!s.count(temp)) {
                        s.insert(temp);
                        v.push_back(temp);
                    }
                }
            }
        }
        return v;
    }
};