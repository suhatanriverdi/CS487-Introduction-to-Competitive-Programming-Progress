// Question Link ---> https://leetcode.com/problems/find-median-from-data-stream/submissions/
class MedianFinder {
	multiset<int> numSet;
	multiset<int>::iterator it;
	int size;
	
public:
    void addNum(int num) {
         numSet.insert(num);
    }
    
    double findMedian() {
        it = numSet.begin();
        size = numSet.size();
        advance(it, size/2);
        if (size & 1) { // Odd
            return *it;
        } 
        else { // Even
            return (double)(*--it + *++it) / 2;
        }
    }
};