/*
  Given preorder and inorder traversal of a tree, construct the binary tree.

  Note:
  You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	if(preorder.empty())
	    return NULL;
	return buildHelper(preorder, 0, inorder, 0, inorder.size()-1);
    }
    TreeNode *buildHelper(vector<int> &preorder, int rt, vector<int> &inorder, int st, int ed)
        {
	    if(st > ed)
		return NULL;
	    int index = st;
	    for(; index <= ed; ++index)
		if(inorder[index] == preorder[rt])
		    break;
	    TreeNode *root = new TreeNode(preorder[rt]);
	    root->left = buildHelper(preorder, rt+1, inorder, st, index-1);
	    root->right = buildHelper(preorder, rt + (index-st) + 1, inorder, index+1, ed);
	    return root;
	}
};
