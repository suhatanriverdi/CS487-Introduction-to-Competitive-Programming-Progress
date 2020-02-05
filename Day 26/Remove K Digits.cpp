// Question Link ---> https://leetcode.com/problems/remove-k-digits/
// Day #26
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }
        string mayHaveLeadingZeros = "", result = "";
        for (int i = k; i < num.size(); i++) {
            mayHaveLeadingZeros += findSmallestInLeft(num, i);
        }
        int i = 0;
        while (i < mayHaveLeadingZeros.size() && mayHaveLeadingZeros[i] == '0') i++;
        for (int j = i; j < mayHaveLeadingZeros.size(); j++) result += mayHaveLeadingZeros[j];
        return (result.size() == 0 ? "0" : result);
    }
    
    char findSmallestInLeft(string &str, int index) {
        char localMinChar = str[index];
        int localMinIndex = index;
        for (int i = index; i>= 0 && str[i] != '.'; i--) {
            if (str[i] <= localMinChar) {
                localMinIndex = i;
                localMinChar = str[i];
            }
        }
        str[localMinIndex] = '.';
        return localMinChar;
    }
};