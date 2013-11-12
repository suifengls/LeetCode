/*
  Given a binary tree, return the postorder traversal of its nodes' values.
  
  For example:
  Given binary tree {1,#,2,3},
      1
       \
        2
       /
      3
  return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root) {
	vector<int> result;
	if(!root)
	    return result;
	stack<TreeNode *> q;
	q.push(root);
	TreeNode *prev = root;
	while(!q.empty())
	{
	    TreeNode *node = q.top();
	    if((!node->left && !node->right) || node->right == prev || node->left == prev)
	    {
		result.push_back(node->val);
		prev = node;
		q.pop();
	    }
	    else
	    {
		if(node->right)
		    q.push(node->right);
		if(node->left)
		    q.push(node->left);
	    }
	}
    }
};
