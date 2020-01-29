// Question Link ---> https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
class Solution {
	struct State {
		int tailX, tailY, headX, headY, dist;
		bool operator==(const State& other) const {
			return tailX == other.tailX && headX == other.headX && tailY == other.tailY && headY == other.headY;
		}
	};
	vector<vector<int>> moves = { {0, 1, 0, 1}, {1, 0, 1, 0}, {0, 0, 1, -1}, {0, 0, -1, 1} };
	class hashFunction {
		public:
			size_t operator()(const State& t) const {
				return t.tailX * t.tailY * t.headX * t.headY + t.tailX + t.tailY + t.headX + t.headY;
			}
	};
public:
	int minimumMoves(vector<vector<int>>& grid) {
		queue<State> states;
		unordered_set<State, hashFunction> visited;
		State endState; int N = grid.size() - 1;
		endState.tailX = N; endState.tailY = N - 1;
		endState.headX = N; endState.headY = N;
		states.push({ 0,0,0,1,0 }); // (x1, y1, x2, y2, dist)
		visited.insert({ 0,0,0,1,0 });
		while (!states.empty()) {
			State curState = states.front(); states.pop();
			for (int i = 0; i < 4; i++) {
				State newNeighbor;
				newNeighbor.tailX = moves[i][0] + curState.tailX;
				newNeighbor.tailY = moves[i][1] + curState.tailY;
				newNeighbor.headX = moves[i][2] + curState.headX;
				newNeighbor.headY = moves[i][3] + curState.headY;
				newNeighbor.dist = curState.dist + 1;
				if (inside(newNeighbor, grid, i, N + 1) && !visited.count(newNeighbor)) {
					states.push(newNeighbor);
					visited.insert(newNeighbor);
					if (reachedFinish(newNeighbor, endState)) {
						return newNeighbor.dist;
					}
				}
			}
		}
		return -1;
	}

	bool reachedFinish(State& curState, State& endState) {
		return (curState == endState);
	}

	bool inside(State& curState, vector<vector<int>>& grid, int moveNumber, int N) {
		if (curState.tailX < 0 || curState.tailX >= N || curState.headX < 0 || curState.headX >= N ||
			curState.tailY < 0 || curState.tailY >= N || curState.headY < 0 || curState.headY >= N ||
			grid[curState.tailX][curState.tailY] || grid[curState.headX][curState.headY]) {
			return false;
		}
		if (moveNumber == 2) { // Clockwise
			if (grid[curState.headX][curState.headY + 1] || curState.tailY != curState.headY) {
				return false;
			}
		}
		if (moveNumber == 3) { // Counter-Clockwise
			if (grid[curState.headX + 1][curState.headY] || curState.tailY == curState.headY) {
				return false;
			}
		}
		return true;
	}
};