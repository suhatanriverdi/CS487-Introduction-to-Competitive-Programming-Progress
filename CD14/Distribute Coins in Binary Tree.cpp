// Question Link ---> https://leetcode.com/problems/distribute-coins-in-binary-tree/
// C++ Version 1 No Global Variable
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int diff = 0;
        postOrderDistribute(root, diff);
        return diff;
    }
    
    int postOrderDistribute(TreeNode *cur, int &diff) {
        if (cur == NULL) {
            return 0;
        }
        cur->val += postOrderDistribute(cur->left, diff) +
        postOrderDistribute(cur->right, diff);
        diff += abs(cur->val - 1);
        return (cur->val - 1);
    }
};

// Java Version 1 No Global Variable
class Solution {
    public int distributeCoins(TreeNode root) {
        int[] diff = {0};
        postOrderDistribute(root, diff);
        return diff[0];
    }
    
    public int postOrderDistribute(TreeNode cur, int[] diff) {
        if (cur == null) {
            return 0;
        }
        cur.val += postOrderDistribute(cur.left, diff) + postOrderDistribute(cur.right, diff);
        diff[0] += Math.abs(cur.val - 1);
        return (cur.val - 1);
    }
}

// Java Version 2 by Using Global Variable
class Solution {
    int diff;
    public int distributeCoins(TreeNode root) {
        diff = 0;
        postOrderDistribute(root);
        return diff;
    }
    
    public int postOrderDistribute(TreeNode cur) {
        if (cur == null) {
            return 0;
        }
        cur.val += postOrderDistribute(cur.left) + postOrderDistribute(cur.right);
        diff += Math.abs(cur.val - 1);
        return (cur.val - 1);
    }
}