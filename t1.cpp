
// t3

ListNode* reverseList(ListNode* head)
{
	if (head == nullptr)
		return head;
	ListNode* cur = pre, * pre = nullptr;
	while (cur->next != nullptr)
	{
		ListNode* n = cur->next;
		cur->next = pre;
		pre = cur;
		cur = n;
	}
	cur->next = pre;
	return cur;
}