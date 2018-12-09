#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode *newHead = NULL;
	ListNode *ans = NULL;
	ListNode *pHead1Tmp, *pHead2Tmp;
	pHead1Tmp = pHead1;
	pHead2Tmp = pHead2;
	if (pHead1Tmp == NULL)
		return pHead2Tmp;
	if (pHead2Tmp == NULL)
		return pHead1Tmp;
	while (pHead1Tmp != NULL && pHead2Tmp != NULL)
	{
		if (pHead1Tmp->val >= pHead2Tmp->val)
		{
			if (newHead == NULL)
				newHead = ans = pHead2Tmp;
			else
			{
				newHead->next = pHead2Tmp;
				newHead = newHead->next;
			}
			pHead2Tmp = pHead2Tmp->next;
		}
		else
		{
			if (newHead == NULL)
				newHead = ans = pHead1Tmp;
			else
			{
				newHead->next = pHead1Tmp;
				newHead = newHead->next;
			}
			pHead1Tmp = pHead1Tmp->next;
		}
	}
	if (pHead1Tmp == NULL)
		newHead->next = pHead2Tmp;
	if (pHead2Tmp == NULL)
		newHead->next = pHead1Tmp;
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}