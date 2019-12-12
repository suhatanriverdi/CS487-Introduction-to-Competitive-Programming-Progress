// Question Link ---> https://leetcode.com/problems/sort-array-by-parity-ii/
// Day #6
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
		vector<int> even;
		vector<int> odd;
		vector<int> res;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] % 2 == 0) { // If it is EVEN
				even.push_back(A[i]);
			}		
			else { // If it is ODD
				odd.push_back(A[i]); // 3, 5, 7
			}
		}
		for (int i = 0; i < A.size() / 2; i++) {
			res.push_back(even[i]);
			res.push_back(odd[i]);
		}
		return res;
    }
};