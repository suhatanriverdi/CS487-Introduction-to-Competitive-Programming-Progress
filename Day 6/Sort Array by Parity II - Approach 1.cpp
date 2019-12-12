// Question Link ---> https://leetcode.com/problems/sort-array-by-parity-ii/
// Day #6
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
		vector<int> res(A.size());
		int e = 0, o = 0;
		for (int a = 0; a < A.size(); a++) {
			if (A[a] % 2 == 0) { // If it is EVEN
				res.at( 2 * e) = A[a];
				e++;
			}		
			else { // If it is ODD
				res.at(2 * o + 1) = A[a];
				o++;
			}
		}
		return res;
    }
};