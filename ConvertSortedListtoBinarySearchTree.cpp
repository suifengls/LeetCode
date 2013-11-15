/*
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
  TreeNode *sortedListToBST(ListNode *head) {
    if(!head)
      return NULL;
    int len = 0;
    ListNode *node = head;
    while(node)
      {
	node = node->next;
	++len;
      }
    return buildHelper(head, 0, len-1);
  }
  TreeNode *buildHelper(ListNode *&head, int st, int ed)
  {
    if(st > ed)
      return NULL;
    int mid = (st+ed)/2;
    TreeNode *left = buildHelper(head, st, mid-1);
    TreeNode *root = new TreeNode(head->val);
    head = head->next;
    TreeNode *right = buildHelper(head, mid+1, ed);
    root->left = left;
    root->right = right;
    return root;
  }
};
