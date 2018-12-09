#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	int n = 0;
	if (pListHead == NULL || k <= 0)
		return NULL;
	ListNode *firstList = pListHead, *secdList = pListHead;

	while(firstList != NULL)
	{
		// cout << n << ":" << k-1 << endl;
		if (n > k-1)
			secdList = secdList->next;
		firstList = firstList->next;
		n++;
	}
	if (n < k)
		return NULL;
	// cout << secdList->val << endl;
	return secdList;
}

int main(int argc, char const *argv[])
{

	return 0;
}