// Question Link ---> https://leetcode.com/problems/shortest-path-with-alternating-colors/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int, int>>> adjList(n); // {index, {neighborIndex, color}}
        vector<vector<int>> distance(n, vector<int>(2, -1)); // {index, {redCost, blueCost}}
        for (int i = 0; i < red_edges.size(); i++) {
            adjList[red_edges[i][0]].push_back({red_edges[i][1], 1}); // Red -> 1
        }
        for (int i = 0; i < blue_edges.size(); i++) {
            adjList[blue_edges[i][0]].push_back({blue_edges[i][1], 0}); // Blue -> 0
        }
        queue<pair<int, bool>> states; // {curNode, Color}
        states.push({0 , 0});
        states.push({0 , 1});
        distance[0] = {0, 0};
        while (!states.empty()) {
            auto cur = states.front(); states.pop();
            for (auto neighbor : adjList[cur.first]) {
                if (neighbor.second != cur.second && distance[neighbor.first][neighbor.second] == -1) { // Alternating Color
                    states.push(neighbor);
                    distance[neighbor.first][neighbor.second] = 1 + distance[cur.first][cur.second];
                }
            }
        }
        int miN, maX;
        vector<int> res;
        for (int i = 0; i < distance.size(); i++) {
            miN = min(distance[i][0], distance[i][1]);
            maX = max(distance[i][0], distance[i][1]);
            res.push_back(miN == -1 ? maX : miN);
        }
        return res;
    }
};