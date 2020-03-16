// Question Link ---> https://www.hackerrank.com/challenges/2d-array/problem
// X and Y are the top left corner's corrdinates
int getHourlassSum(vector<vector<int>> &arr, int X, int Y) {
    int size = arr.size(), remain = 3, sum = arr[X + 1][Y + 1]; // Save Middle value first
    // Get sum of up and bottom rows
    while (remain--) {
        sum += arr[X][Y]; // Up
        sum += arr[X + 2][Y++]; // Bottom
    }
    return sum;
}

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int maxSum = INT_MIN;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            maxSum = max(maxSum, getHourlassSum(arr, i, j));
        }
    }
    return maxSum;
}