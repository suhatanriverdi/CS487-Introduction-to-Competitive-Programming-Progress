// Question Link ---> https://leetcode.com/problems/contains-duplicate-ii/
// Day #24

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> numIdxMap; // {number, index}
		for (int i = 0; i < nums.size(); i++) {
			// Check if map does not contain num[i]
			if (!numIdxMap.count(nums[i])) {
				numIdxMap.insert({ nums[i], i }); // Insert
			}
			// If map already contains the current number and 
			// If the distance of inxdexes between currentNumber and containedNumber is <= k
			else if (numIdxMap.count(nums[i]) && abs(numIdxMap[nums[i]] - i) <= k) {
				return true; // We found what we want, return true!
			}
			numIdxMap[nums[i]] = i;
		}
		return false;
	}
};