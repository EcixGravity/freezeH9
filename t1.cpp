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


//t2
int findStr(string str, string mod)
{
	reverse(mod.begin(), mod.end());
	int index = 0;
	while (mod[index] == '*')
		++index;
	int len = str.size(), len2 = mod.size();

	for (int i = index; i < len ; ++i)
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
*/



//t1
vector<int> getWakeLockContrib(vector<vector<int> >& wakeLock) {
	int len = wakeLock.size();
	vector<int> res(len, 0);
	for (int i = 0; i < len; ++i)
	{
		int size = wakeLock[i].size();
		for (int j = 0; j < size; j += 2)
			res[i] += wakeLock[i][j + 1] - wakeLock[i][j];
	}
	return res;
}