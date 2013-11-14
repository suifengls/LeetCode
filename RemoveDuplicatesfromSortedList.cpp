/*
  Given a sorted linked list, delete all duplicates such that each element appear only once.

  For example,
  Given 1->1->2, return 1->2.
  Given 1->1->2->3->3, return 1->2->3.
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
	ListNode *p = head, *q = head->next;
	while(q)
	{
	    while(q && p->val == q->val)
		q = q->next;
	    p->next = q;
	    p = p->next;
	    if(!q)
		return head;
	    else
		q = q->next;
	}
	return head;
    }
};
