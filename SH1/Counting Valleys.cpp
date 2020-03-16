// Question Link ---> https://www.hackerrank.com/challenges/counting-valleys/problem
int countingValleys(int n, string s) {
    vector<int> acc(n + 1, 0);
    // Convert string into 1s (Up) and -1s (Down) vector -> [1,1,-1]
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            acc[i + 1] = 1;
        }
        else {
            acc[i + 1] = -1;
        }
    }
    queue<int> zerosQueue; // holds index of each point at sea level
    zerosQueue.push(0); // first point
    // Get accumulator vector [1,1,-1] -> [1,2,1]
    for (int i = 2; i < n + 1; i++) {
        acc[i] += acc[i - 1];
        if (acc[i] == 0) {
            zerosQueue.push(i);
        }
    }
    int numberOfValleys = 0;
    while (zerosQueue.size() != 1) {
        int curSeaLevel = zerosQueue.front();
        zerosQueue.pop();
        if (acc[curSeaLevel + 1] < 0) { // Valley Found
            numberOfValleys++;
        }
    }
    return numberOfValleys;
}