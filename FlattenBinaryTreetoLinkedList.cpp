/*
  Given a binary tree, flatten it to a linked list in-place.
  
  For example,
  Given

         1
        / \
       2   5
      / \   \
     3   4   6
  The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
  click to show hints.

  Hints:
  If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
  void flatten(TreeNode *root) {
    if(!root)
      return;
    flattenHelper(root);
  }
  TreeNode *flattenHelper(TreeNode *root)
  {
    if(!root->left && !root->right)
      return root;
    TreeNode *rhead = NULL;
    if(root->right)
      rhead = flattenHelper(root->right);
    TreeNode *ltail = root;
    if(root->left)
      {
	TreeNode *lhead = flattenHelper(root->left);
	root->left = NULL;
	root->right = lhead;
	while(ltail->right)
	  ltail = ltail->right;
      }
    if(rhead)
      {
	ltail->right = rhead;
	rhead->left = NULL;
      }
    return root;
  }
};
