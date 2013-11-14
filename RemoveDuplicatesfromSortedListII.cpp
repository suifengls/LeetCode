/*
  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

  For example,
  Given 1->2->3->3->4->4->5, return 1->2->5.
  Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
	if(!head || !head->next)
	    return head;
	ListNode dummy(0);
	dummy.next = head;
	ListNode *p = &dummy;
	ListNode *q = p->next->next;
	while(q)
	{
	    if(q->val != p->next->val)
		p = p->next;
	    else
	    {
		while(q && q->val == p->next->val)
		    q = q->next;
		p->next = q;
	    }
	    if(!q)
		return dummy.next;
	    else
		q = q->next;
	}
	return dummy.next;
    }
};
