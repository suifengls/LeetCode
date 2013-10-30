/*
  Given a linked list, determine if it has a cycle in it.
  
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
    bool hasCycle(ListNode *head) {
	if(!head)
	    return false;
	ListNode *fast = head->next;
	ListNode *slow = head;
	while(fast && fast->next && fast != slow)
	{
	    fast = fast->next->next;
	    slow = slow->next;
	}
	if(!fast || !fast->next)
	    return false;
	else
	    return true;
    }
};
