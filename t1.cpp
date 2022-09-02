/*
// t3

ListNode* reverseList(ListNode* head)
{
	if (head == nullptr)
		return head;
	ListNode* cur = head;
	ListNode* pre = nullptr;
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
*/

//t2
int findStr(string str, string mod)
{
	reverse(mod.begin(), mod.end());
	int index = 0;
	while (mod[index] == '*')
		++index;
	int len = str.size(), len2 = mod.size();

	for (int i = index; i < len - len2; ++i)
	{
		if (mod[index] == str[i])
		{
			for (int j = index; j < len2; ++j)
			{
				if (mod[j] != str[i + j - index] && mod[j] != '*')
					break;
				if (j == len2 - 1)
					return i - index + len2 - 1;
			}
		}
	}
	return -1;
}
