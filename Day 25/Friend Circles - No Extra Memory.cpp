// Question Link ---> https://leetcode.com/problems/friend-circles/
// Day #25
class Solution {
public:
	int findCircleNum(vector<vector<int>> &M) {
		int numOfConnectedFriendGroups = 0;
		vector<bool> visited(M.size(), false); // Try without visited arr! may be we don't need this
		queue<int> friends;
		for (int cur = 0; cur < M.size(); cur++) {
			if (!visited[cur]) {
				bool anyFriendFound = false;
				friends.push(cur);
				while (!friends.empty()) {
					int currentFriend = friends.front();
					friends.pop();
					for (int i = 0; i < M.size(); i++) {
						if (M[currentFriend][i] == 1 && !visited[i]) { // Friend found
							friends.push(i);
							visited[i] = true;
							anyFriendFound = true;
						}
					}
				}
				if (anyFriendFound) {
					numOfConnectedFriendGroups++;
				}
			}
		}
		return numOfConnectedFriendGroups;
	}
};