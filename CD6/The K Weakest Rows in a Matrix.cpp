// Question Link ---> https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        multimap<int, int> soldierRow; // {soldier, row}
        int M = mat.size();
        int N = mat[0].size();
        for (int i = 0; i < M; i++) {
            int j = 1;
            for (; j < N; j++) {
                if (mat[i][j] != 0) {
                    mat[i][j] += mat[i][j - 1];
                } else break;
            }
            soldierRow.insert({mat[i][j - 1], i});
        }
        auto it = soldierRow.begin();
        for (int i = 0; i < k && it != soldierRow.end(); i++, it++) {
            res.push_back(it->second);
        }
        return res;
    }
};