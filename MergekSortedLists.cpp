/*
  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class cmp
{
public:
    bool operator()(ListNode *a, ListNode *b)
	{
	    return a->val > b->val;
	}
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
	priority_queue<ListNode*, vector<ListNode *>, cmp> heap;
	for(int i = 0; i < lists.size(); ++i)
	    if(lists[i])
		heap.push(lists[i]);
	ListNode dummy(0), *curr = &dummy;
	while(!heap.empty())
	{
	    ListNode *node = heap.top();
	    heap.pop();
	    curr->next = node;
	    curr = curr->next;
	    if(node->next)
		heap.push(node->next);
	}
	return dummy.next;
    }
};
