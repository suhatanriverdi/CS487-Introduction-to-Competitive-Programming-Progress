// Question Link ---> https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>(0));
        vector<int> incomingEdges(numCourses, 0), topSort;
        vector<bool> visited(numCourses, false);
        // Create an Adjacency List Representation
        for (auto pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            incomingEdges[pre[0]]++;
        }
        // Find the root nodes
        queue<int> statesQueue;
        bool hasNoRoot = true;
        for (int i = 0; i < incomingEdges.size(); i++) {
            int node = incomingEdges[i];
            if (node == 0) { // Root Nodes
                statesQueue.push(i);
                topSort.push_back(i);
                visited[i] = true;
                //cout << "HERE!" << i << endl;
                hasNoRoot = false;
            }
        }
        if (hasNoRoot) {
            return false;
        }
        
        // Run BFS
        while (!statesQueue.empty()) {
            auto cur = statesQueue.front();
            statesQueue.pop();
            for (auto children : adjList[cur]) {
                if (visited[children] == true) {
                    return false;
                }
                if (--incomingEdges[children] == 0) {
                    statesQueue.push(children);
                    visited[children] = true;
                    topSort.push_back(cur);
                }
            }
        }
        return topSort.size() == numCourses;
    }
};