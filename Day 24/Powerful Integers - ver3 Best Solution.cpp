// Question Link ---> https://leetcode.com/problems/powerful-integers/
// Day #24

class Solution {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		unordered_set<int> s;
		vector<int> v;
		int i = 0, j = 0;
		if (x > 1) while (pow(x, i++) < bound);
		if (y > 1) while (pow(y, j++) < bound);
		for (int k = 0; k <= i; k++) {
			for (int l = 0; l <= j; l++) {
				long long int temp = pow(x, k) + pow(y, l);
				if (temp > 0 && temp <= bound) {
					if (!s.count(temp)) {
						s.insert(temp);
						v.push_back(temp);
					}
				}
			}
		}
		return v;
	}
};