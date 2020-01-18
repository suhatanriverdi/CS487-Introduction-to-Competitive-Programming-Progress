// Question Link ---> https://leetcode.com/problems/flood-fill/
// Day #25
#include <iostream>    
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		// We need to consider starting pixel, if it is alrealy filled with newColor then return
		if (image[sr][sc] != newColor) {
			int oldColor = image[sr][sc];
			dfs(image, sr, sc, newColor, oldColor);
		}
		return image;
	}

	void dfs(vector<vector<int>> &image, int x, int y, int &newColor, int &oldColor) {
		if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == oldColor) {
			image[x][y] = newColor;
			dfs(image, x, y + 1, newColor, oldColor);
			dfs(image, x, y - 1, newColor, oldColor);
			dfs(image, x - 1, y, newColor, oldColor);
			dfs(image, x + 1, y, newColor, oldColor);
		}
	}
};

int main(void) {
	vector<vector<int>> res, image = { {0, 0, 0}, {0, 1, 1} };
	int sr = 1, sc = 1, newColor = 1;
	//vector<vector<int>> res, image = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
	//int sr = 1, sc = 1, newColor = 2;
	Solution obj;
	res = obj.floodFill(image, sr, sc, newColor);
	cout << "Result: \n";
	for (auto row : image) {
		for (auto pixel : row) {
			cout << pixel << " ";
		}
		cout << endl;
	}
}