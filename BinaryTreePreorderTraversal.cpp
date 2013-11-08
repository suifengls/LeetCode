/*
  Given a binary tree, return the preorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
        1
         \
          2
	 /
        3
  return [1,2,3].

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
    vector<int> preorderTraversal1(TreeNode *root) {
	vector<int> result;
	if(!root)
	    return result;
	traversalHelper(root, result);
	return result;
    }
    void traversalHelper(TreeNode *root, vector<int> &result)
	{
	    result.push_back(root->val);
	    if(root->left)
		traversalHelper(root->left, result);
	    if(root->right)
		traversalHelper(root->right, result);
	}
};

class Solution {
public:
    vector<int> preorderTraversal2(TreeNode *root) {
	vector<int> result;
	if(!root)
	    return result;
	stack<TreeNode *> q;
	q.push(root);
	while(!q.empty())
	{
	    TreeNode *node = q.top();
	    q.pop();
	    result.push_back(node->val);
	    if(node->right)
		q.push(node->right);
	    if(node->left)
		q.push(node->left);
	}
	return result;
    }
};
