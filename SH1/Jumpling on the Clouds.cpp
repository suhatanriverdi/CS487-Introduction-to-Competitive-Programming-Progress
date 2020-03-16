// Question Link ---> https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
int jumpingOnClouds(vector<int> c) {
    int cnt = 0, size = c.size(), i = 0;
    while (i < size - 1) {
        if (i + 2 < size && c[i + 2] == 0) {
            i += 2;
            cnt++;
        }
        else if (i + 1 < size && c[i + 1] == 0) {
            i += 1;
            cnt++;
        }
    }
    return cnt;
}