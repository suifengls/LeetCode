/*
  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
  
  You must do this in-place without altering the nodes' values.
  
  For example,
  Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
	if(!head || !head->next || !head->next->next)
	    return;
	ListNode *fast = head, *slow = head;
	while(fast->next && fast->next->next)
	{
	    fast = fast->next->next;
	    slow = slow->next;
	}
	// reverse last half
	ListNode *half = reverse(slow);
	fast = head;
	while(half)
	{
	    ListNode *tmp1 = fast->next;
	    ListNode *tmp2 = half->next;
	    fast->next = half;
	    half->next = tmp1;
	    half = tmp2;
	    fast = tmp1;
	}
    }
    ListNode *reverse(ListNode *root)
	{
	    ListNode *node = root->next, *next = NULL;
	    root->next = NULL;
	    while(node->next)
	    {
		ListNode *tmp = node->next;
		node->next = next;
		next = node;
		node = tmp;
	    }
	    node->next = next;
	    return node;
	}
};
