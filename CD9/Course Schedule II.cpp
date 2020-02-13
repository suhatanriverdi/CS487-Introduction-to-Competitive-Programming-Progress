// Question Link ---> https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>(0));
        vector<int> incomingEdges(numCourses, 0), topSort;
        // Create an Adjacency List Representation
        for (auto pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            incomingEdges[pre[0]]++;
        }
        // Find the root nodes
        queue<int> statesQueue;
        for (int i = 0; i < incomingEdges.size(); i++) {
            int node = incomingEdges[i];
            if (node == 0) { // Root Nodes
                statesQueue.push(i);
                topSort.push_back(i);
            }
        }
        // Run BFS
        while (!statesQueue.empty()) {
            auto cur = statesQueue.front();
            statesQueue.pop();
            for (auto children : adjList[cur]) {
                if (--incomingEdges[children] == 0) {
                    statesQueue.push(children);
                    topSort.push_back(children);
                }
            }
        }
        return (topSort.size() == numCourses ? topSort : vector<int>());
    }
};