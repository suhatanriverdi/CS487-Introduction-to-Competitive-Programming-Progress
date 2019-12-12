// Question Link ---> https://leetcode.com/problems/range-sum-of-bst/
// Day #14
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        traverse(root, L, R);
        return sum;
    }
    
    void traverse(TreeNode *current, int &l_val, int &r_val) {
    	if (current == NULL) return;
		if (current->val >= l_val && current->val <= r_val) sum += current->val;
		if (current->val < r_val) traverse(current->right, l_val, r_val);
		if (current->val > l_val) traverse(current->left, l_val, r_val);
	}
};

int main(void) {
	// test-1
	TreeNode* node = new TreeNode(2);
	node->left = new TreeNode(2);
	node->right = new TreeNode(5);
	node->right->left = new TreeNode(5);
	node->right->right = new TreeNode(7);
	
	// Test-2
//	TreeNode* node = new TreeNode(1);
//	node->left = new TreeNode(1);
//	node->right = new TreeNode(2);
//	node->left->left = new TreeNode(1);
//	node->left->right = new TreeNode(1);
//	node->right->left = new TreeNode(2);
//	node->right->right = new TreeNode(2);

	Solution obj;
	cout << "Output: " << obj.rangeSumBST(node, 7, 15);
	return 0;
}
