// Question Link ---> https://leetcode.com/problems/reduce-array-size-to-the-half/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> orderedFreqs;
        unordered_map<int, int> freqs; // {num, freq}
        for (auto i : arr) freqs[i]++;
        if (freqs.size() == 1) return 1;
        for (auto i : freqs) orderedFreqs.push_back(i.second);
        int half = arr.size() / 2, sum = 0, setCnt = 0; 
        sort(orderedFreqs.begin(), orderedFreqs.end(), greater<int>());
        for (auto curFreq : orderedFreqs) {
            sum += curFreq;
            setCnt++;
            if (sum >= half) {
                return setCnt;
            }
        }
        return setCnt;
    }
};