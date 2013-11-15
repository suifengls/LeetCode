/*
  Given inorder and postorder traversal of a tree, construct the binary tree.
  
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	if(postorder.empty())
	    return NULL;
	return buildHelper(inorder, 0, inorder.size()-1, postorder, postorder.size()-1);
    }
    TreeNode *buildHelper(vector<int> &inorder, int st, int ed, vector<int> &postorder, int rt)
        {
	    if(st > ed)
		return NULL;
	    int index = st;
	    for(; index <= ed; ++index)
		if(inorder[index] == postorder[rt])
		    break;
	    TreeNode *root = new TreeNode(postorder[rt]);
	    root->left = buildHelper(inorder, st, index-1, postorder, rt-(ed-index)-1);
	    root->right = buildHelper(inorder, index+1, ed, postorder, rt-1);
	    return root;
	}
};
