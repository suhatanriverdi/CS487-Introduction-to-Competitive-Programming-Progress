// Question Link ---> https://leetcode.com/problems/loud-and-rich/
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int size = quiet.size();
        vector<vector<int>> graph(size);
        vector<int> ans(size, -1);
        // Constructs Graph
        for (auto rich : richer) {
            graph[rich[1]].push_back(rich[0]);
        }
        // Run DFS for each person on Graph
        for (int i = 0; i < size; i++) {
            dfs(graph, quiet, ans, i);
        }
        return ans;
    }

    int dfs(vector<vector<int>> &graph, vector<int> &quiet, vector<int> &ans, int currentPerson) {
        // Check and return whether if the answer is already calculated or not
        if (ans[currentPerson] >= 0) {
            return ans[currentPerson];
        }
        // Save at least person's value itself in case that no richer and least loud person found in search
        ans[currentPerson] = currentPerson;
        for (auto child : graph[currentPerson]) {
            if (quiet[dfs(graph, quiet, ans, child)] < quiet[ans[currentPerson]]) {
                ans[currentPerson] = ans[child];
            }
        }
        return ans[currentPerson];
    }
};