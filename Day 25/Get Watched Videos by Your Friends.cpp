// Question Link ---> https://leetcode.com/problems/get-watched-videos-by-your-friends/
// Day #25
class Solution {
public:
    static bool cmp (pair<string, int> &a, pair<string, int> &b) {
        if (a.second < b.second) {
            return true;
        }
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return false;
    }
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> res;
        unordered_map<string, int> videoFreqs;
        vector<pair<string, int>> sortedVideos;
        int size = friends.size();
        vector<vector<int>> adjList(size);
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++) {
            for (auto myFriends : friends[i]) {
                adjList[i].push_back(myFriends);
            }
        }
        int curLevel = 0;
        queue<int> friendsQueue;
        friendsQueue.push(id);
        visited[id] = true;
        bool curLevelFound = false;
        while (!friendsQueue.empty()) {
            int qSize = friendsQueue.size();
            while (qSize--) {
                int curFriend = friendsQueue.front();
                friendsQueue.pop();
                if (curLevel == level) {
                    for (auto &watchedVideo : watchedVideos[curFriend]) {
                        videoFreqs[watchedVideo]++;
                    }
                    curLevelFound = true;
                }
                for (auto myFriends : adjList[curFriend]) {
                    if (visited[myFriends] == false) {
                        friendsQueue.push(myFriends);
                        visited[myFriends] = true;
                    }
                }
            }
            if (curLevelFound) {
                break;
            }
            curLevel++;
        }
        for (auto pair : videoFreqs) {
            sortedVideos.push_back({pair.first, pair.second});
        }
        sort(sortedVideos.begin(), sortedVideos.end(), cmp);
        for (auto pair : sortedVideos) {
            res.push_back(pair.first);
        }
        return res;
    }
};