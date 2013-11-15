/*
  Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

  For example:
  Given binary tree {3,9,20,#,#,15,7},
          3
         / \
	9  20
          /  \
	 15   7
  return its zigzag level order traversal as:
  [
    [3],
    [20,9],
    [15,7]
  ]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int> > result;
	if(!root)
	    return result;
	vector<int> level;
	queue<TreeNode *> q;
	int count = 1, ncount = 0;
	int rv = 0;
	q.push(root);
	while(!q.empty())
	{
	    TreeNode *node = q.front();
	    q.pop();
	    level.push_back(node->val);
	    --count;
	    if(node->left)
	    {
		q.push(node->left);
		++ncount;
	    }
	    if(node->right)
	    {
		q.push(node->right);
		++ncount;
	    }
	    if(count == 0)
	    {
		count = ncount;
		ncount = 0;
		++rv;
		if(rv % 2 == 0)
		    reverse(level.begin(), level.end());
		result.push_back(level);
		level.clear();
	    }
	}
	return result;
    }
};
