// Question Link ---> https://leetcode.com/problems/top-k-frequent-elements/
// Day #19
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m; // {num, freq}
        priority_queue<pair<int, int>> pq;
        for (auto num: nums) m[num]++;
        for (auto i : m) pq.push({i.second, i.first});
        for (int i = 0; i < k && !pq.empty(); i++) { res.push_back(pq.top().second); pq.pop(); }
        return res;
    }
};