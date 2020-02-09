// Question Link ---> https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int nonLeafSum = 0, till = arr.size() - 1;
        map<pair<int, int>, int> pairProd;
        while (till--) {
            vector<int> curVec = getUpperLevel(arr, pairProd);
            nonLeafSum += curVec.back();
            curVec.pop_back();
            arr = curVec;
        }
        return nonLeafSum;
    }

    vector<int> getUpperLevel(vector<int> &arr, map<pair<int, int>, int> &pairProd) {
        int M = arr.size();
        int curRowProdMin = INT_MAX, prod = INT_MAX, minProdIdx;
        vector<int> nextArr;
        for (int i = 0; i + 1 < M; i++) { // Fill last row with arr
            if (pairProd.count({arr[i], arr[i + 1]})) {
                prod = pairProd[{arr[i], arr[i + 1]}];
            } else {
                prod = arr[i] * arr[i + 1];
                pairProd.insert({{arr[i], arr[i + 1]}, prod});
            }
            if (prod < curRowProdMin) {
                minProdIdx = (arr[i] < arr[i + 1] ? i : (i + 1));
                curRowProdMin = prod;
            }
        }
        arr[minProdIdx] = -1;
        for (int i = 0; i < M; i++) {
            if (arr[i] > 0) {
                nextArr.push_back(arr[i]);
            }
        }
        nextArr.push_back(curRowProdMin);
        return nextArr;
    }
};