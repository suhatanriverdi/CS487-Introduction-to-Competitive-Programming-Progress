// Question Link ---> https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		long long int size = heights.size();
		long long int maxArea = 0;
		vector<vector<int>> consecutiveHeightFreqs; // {height, NumberOfHeightsConsecutively}
		removeDuplicatesSaveFreqs(heights, consecutiveHeightFreqs);
		for (int i = 0; i < consecutiveHeightFreqs.size(); i++) {
            if (consecutiveHeightFreqs[i][0] != 0) {
    			maxArea = max(maxArea, findAreaOfRect(i, consecutiveHeightFreqs));
            }
		}
		return maxArea;
	}

	long long int findAreaOfRect(int center, vector<vector<int>>& heightsFreq) {
		long long int areaSum = heightsFreq[center][0] * heightsFreq[center][1], centerNum = heightsFreq[center][0]; // Area of Ourselves
		// Look for right
		for (int i = center + 1; i < heightsFreq.size() && heightsFreq[i][0] >= centerNum; i++) {
			areaSum += centerNum * heightsFreq[i][1];
		}
		// Look for left
		for (int i = center - 1; i >= 0 && heightsFreq[i][0] >= centerNum; i--) {
			areaSum += centerNum * heightsFreq[i][1];
		}
		return areaSum;
	}

	// Makes this [ 1, 1, 4, 4, 4, 5, 5, 1 ] -> into this [ 1(2), 4(3), 5(2), 1(1) ] (Frequencies of each consecutive heights)
	void removeDuplicatesSaveFreqs(vector<int>& nums, vector<vector<int>> &consecutiveHeightFreqs) {
		int size = nums.size(), currentHeight, i = 0, heightCount;
		for (; i < size; i++) {
			currentHeight = nums[i], heightCount = 1;
            for (int j = i + 1; j < size && currentHeight == nums[j]; j++, i++) {
                heightCount++;
            }
            consecutiveHeightFreqs.push_back({ currentHeight, heightCount });
		}
	}
};