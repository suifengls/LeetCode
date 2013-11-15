/*
  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
	return sortHelper(num, 0, num.size()-1);
    }
    TreeNode *sortHelper(vector<int> &num, int st, int ed)
        {
	    if(st > ed)
		return NULL;
	    else
	    {
		int mid = (st+ed)/2;
		TreeNode *root = new TreeNode(num[mid]);
		root->left = sortHelper(num, st, mid-1);
		root->right = sortHelper(num, mid+1, ed);
		return root;
	    }
	}
};
