/*
  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

  Follow up:
  Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
	if(!head || !head->next)
	    return NULL;
	ListNode *fast = head, *slow = head;
	do
	{
	    fast = fast->next->next;
	    slow = slow->next;
	}while(fast && fast->next && slow != fast);
	if(!fast || !fast->next)
	    return NULL;
	else
	    slow = head;
	while(slow != fast)
	{
	    fast = fast->next;
	    slow = slow->next;
	}
	return fast;
    }
};
