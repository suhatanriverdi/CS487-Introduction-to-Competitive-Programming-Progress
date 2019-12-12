// Question Link ---> https://leetcode.com/problems/two-sum/
// Day #3
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    vector<int> twoSum(vector<int>& nums, int target) {
	        vector<int> ans;
	        for (int i = 0; i < nums.size(); i++) {
	        	for (int j = 1; j < nums.size(); j++) {
					if (j == i) j++;
		        	if (nums[j] + nums[i] == target) {
		        		ans.push_back(i);
		        		ans.push_back(j);
		        		return ans;
					}
				}
			}
			return ans;
	    }
};

int main() {
	vector<int> nums = {2, 7, 11, 15};
	vector<int> sum;
	int target = 9;
	Solution obj;
	sum = obj.twoSum(nums, target);
	for (int i=0 ; i<sum.size(); i++) cout << sum[i] << " ";
    return 0;
}
