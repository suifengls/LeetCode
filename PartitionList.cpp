/*
  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

  You should preserve the original relative order of the nodes in each of the two partitions.

  For example,
  Given 1->4->3->2->5->2 and x = 3,
  return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
	if(!head || !head->next)
	    return head;
	ListNode *lh, *lt, *rh, *rt;
	lh = lt = rh = rt = NULL;
	ListNode *curr = head;
	while(curr)
	{
	    if(curr->val < x)
	    {
		if(!lh)
		{
		    lh = new ListNode(curr->val);
		    lt = lh;
		}
		else
		{
		    lt->next = new ListNode(curr->val);
		    lt = lt->next;
		}
	    }
	    else
	    {
		if(!rh)
		{
		    rh = new ListNode(curr->val);
		    rt = rh;
		}
		else
		{
		    rt->next = new ListNode(curr->val);
		    rt = rt->next;
		}
	    }
	    curr = curr->next;
	}
	if(!lh)
	    return rh;
	else
	    lt->next = rh;
	return lh;
    }
};
