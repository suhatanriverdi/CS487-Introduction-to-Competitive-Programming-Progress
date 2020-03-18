// Question Link ---> https://www.hackerrank.com/challenges/equality-in-a-array/problem
int equalizeArray(vector<int> arr) {
    int numOfVals = arr.size(), maxFreq = INT_MIN;
    unordered_map<int, int> freqs;
    for (int num : arr) {
        freqs[num]++;
    }
    for (auto freq : freqs) {
        maxFreq = max(maxFreq, freq.second);
    }
    return numOfVals - maxFreq;
}