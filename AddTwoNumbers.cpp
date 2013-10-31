/*
  You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
  
  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *head = NULL, *curr;
	int carry = 0;
	while(l1 || l2 || carry)
	{
	    int v1 = 0, v2 = 0;
	    if(l1)
	    {
		v1 = l1->val;
		l1 = l1->next;
	    }
	    if(l2)
	    {
		v2 = l2->val;
		l2 = l2->next;
	    }
	    int sum = v1 + v2 + carry;
	    carry = sum / 10;
	    ListNode *node = new ListNode(sum%10);
	    if(!head)
	    {
		head = node;
		curr = head;
	    }
	    else
	    {
		curr->next = node;
		curr = curr->next;
	    }
	}
	return head;
    }
};
