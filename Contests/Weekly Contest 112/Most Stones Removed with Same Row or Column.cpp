// Question Link ---> https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
class Solution {
public:
	int removeStones(vector<vector<int>>& stones) {
		queue<pair<int, int>> nodes;
		int largestPossibleNumOfMoves = 0, curMaxMoves;
		for (int i = 0; i < stones.size(); i++) {
			if (stones[i][0] != -1) {
				nodes.push({ stones[i][0], stones[i][1] });
				stones[i][0] = -1; // Mark As Visited
			}
			curMaxMoves = 0;
			while (!nodes.empty()) {
				auto cur = nodes.front(); nodes.pop();
				for (int i = 0; i < stones.size(); i++) {
					int nx = stones[i][0], ny = stones[i][1];
					if (nx != -1 && (nx == cur.first || ny == cur.second)) {
						nodes.push({ stones[i][0], stones[i][1] });
						stones[i][0] = -1; // Mark as visited
						curMaxMoves += 1;
					}
				}
			}
			largestPossibleNumOfMoves += curMaxMoves;
		}
		return largestPossibleNumOfMoves;
	}
};