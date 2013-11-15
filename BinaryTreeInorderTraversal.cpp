/*
  Given a binary tree, return the inorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
        1
         \
	  2
	 /
        3
  return [1,3,2].

  Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root) {
	vector<int> result;
	if(!root)
	    return result;
	stack<TreeNode *> stk;
	TreeNode *node = root;
	stk.push(root);
	while(!stk.empty() || node)  // stop consition
	{
	    if(node == root)
		node = root->left;
	    while(node)
	    {
		stk.push(node);
		node = node->left;
	    }
	    node = stk.top();
	    stk.pop();
	    result.push_back(node->val);
	    node = node->right;
	}
	return result;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
	vector<int> inorder;
	inorderHelper(root, inorder);
	return inorder;
    }
    void inorderHelper(TreeNode *root, vector<int> &inorder)
	{
	    if(!root)
		return;
	    inorderHelper(root->left, inorder);
	    inorder.push_back(root->val);
	    inorderHelper(root->right, inorder);
	}
};  
