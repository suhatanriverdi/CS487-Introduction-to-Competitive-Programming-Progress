// Question Link ---> https://leetcode.com/problems/k-closest-points-to-origin/
// Day #7
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<double, vector<int>> m;
        vector<vector<int>> res;
        for (auto point : points) m.insert({calcDistance(point), point});
        for (auto it = m.begin(); it != m.end() && K > 0; it++, K--) res.push_back(it->second);
        return res;
    }
    
    double calcDistance(vector<int> &pair) {
        return sqrt(pow(pair[0], 2) + pow(pair[1], 2));
    }
};