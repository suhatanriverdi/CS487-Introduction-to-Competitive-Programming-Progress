// Question Link ---> https://www.hackerrank.com/challenges/repeated-string/problem
long repeatedString(string s, long n) {
    long long int strSize = s.size();
    long long int cntA = 0, remain = n % strSize, repeat = n / strSize;
    for (char c : s) {
        if (c == 'a') {
            cntA++;
        }
    }
    cntA = repeat * cntA;
    for (long int i = 0; remain > 0; remain--, i++) {
        if (s[i] == 'a') {
            cntA++;
        }
    }
    return cntA;
}