// Question Link ---> https://leetcode.com/problems/flood-fill/
// Day #25
#include <iostream>    
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		queue<pair<int, int>> pixelCoordinates;
		vector<vector<bool>> isPainted(image.size(), vector<bool>(image[0].size(), false));
		pixelCoordinates.push({sr, sc});
		int originalColor = image[sr][sc]; // We use this for checking visited / not-visited
		image[sr][sc] = newColor; // We filled start pixel with newColor (marked as visited)
		isPainted[sr][sc] = true; // Marked as filled
		while (!pixelCoordinates.empty()) {
			pair<int, int> currentPixel = pixelCoordinates.front();
			pixelCoordinates.pop();
			// Search 4-Directions
			pair<int, int> directions[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
			for (auto direction : directions) {
				int newX = direction.first + currentPixel.first;
				int newY = direction.second + currentPixel.second;
				if (newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size() && image[newX][newY] == originalColor && !isPainted[newX][newY]) {
					image[newX][newY] = newColor; // Fill pixel with new color
					isPainted[newX][newY] = true;
					pixelCoordinates.push({ newX, newY }); // Save new filled pixel for neighboring pixels
				}
			}
		}
		return image;
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