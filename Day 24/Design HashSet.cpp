// Question Link ---> https://leetcode.com/problems/design-hashset/
// Day #24
class MyHashSet {
public:
    int set[1000001]; // all elements -1
    /** Initialize your data structure here. */
    MyHashSet() {
        for (int i = 0; i < 1000001; i++) {
            set[i] = -1;
        }
    }
    
    void add(int key) {
        set[key] = 1;
    }
    
    void remove(int key) {
        set[key] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return (set[key] > 0);
    }
};