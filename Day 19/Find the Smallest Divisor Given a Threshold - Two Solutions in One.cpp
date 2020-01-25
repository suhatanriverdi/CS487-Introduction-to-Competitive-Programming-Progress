// Question Link ---> https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Day #19

// C++ Two Solutions Comparison for Beginners (Time Limit Exceeded vs Binary Search)
// We basically looking for each divisor's sum starting from 1 to max possible threshold (We know the answer is guaranteed), then we check if the sum is less than or equal to the given threshold, if so we return the current divisor that satisfies the sum.
// Naive Approach - Got Time Limit Exceeded
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int curDivisor, L = 0, R = 1000000;
        while (L <= R) {
            curDivisor = (L + R) / 2;
            long long int sum = sumForCurDivisor(curDivisor, nums);
            if (sum <= threshold) {
                R = curDivisor - 1;
            } else {
                L = curDivisor + 1;
            }
        }
        return L;
    }
    
    long long int sumForCurDivisor(int divisor, vector<int>& nums) {
        long long int sum = 0;
        for (auto num : nums) {
            int tmp = num / divisor;
            sum += tmp;
            if (num % divisor != 0) {
                sum++;
            }
        }
        return sum;
    }
};

// Binary Search Solution
// Now, we can optimize above solution in a way that we don't have to try each divisor one by one, if we know the sum is below the threshold then we can restrict the range by using binary search.
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int curDivisor, L = 1, R = 1000000;
        while (L <= R) {
            curDivisor = (L + R) / 2;
            long long int sum = sumForCurDivisor(curDivisor, nums);
            if (sum <= threshold) {
                R = curDivisor - 1;
            } else {
                L = curDivisor + 1;
            }
        }
        return L;
    }
    
    long long int sumForCurDivisor(int divisor, vector<int>& nums) {
        long long int sum = 0;
        for (auto num : nums) {
            int tmp = num / divisor;
            sum += tmp;
            if (num % divisor != 0) {
                sum++;
            }
        }
        return sum;
    }
};