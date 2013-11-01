/*
  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
  
  For example:
  Given binary tree {3,9,20,#,#,15,7},
          3
         / \
        9  20
	  /  \
	 15   7
  return its level order traversal as:
  [
   [3],
   [9,20],
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
    vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int> > orders;
	if(!root)
	    return orders;
	queue<TreeNode *> level;
	vector<int> lv;
	level.push(root);
	int count = 1, ncount = 0;
	while(!level.empty())
	{
	    TreeNode *node = level.front();
	    level.pop();
	    lv.push_back(node->val);
	    --count;
	    if(node->left)
	    {
		++ncount;
		level.push(node->left);
	    }
	    if(node->right)
	    {
		++ncount;
		level.push(node->right);
	    }
	    if(count == 0)
	    {
		orders.push_back(lv);
		lv.clear();
		count = ncount;
		ncount = 0;
	    }
	}
	return orders;
    }
};
