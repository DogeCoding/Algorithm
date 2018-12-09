#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode *preNode, *nextNode;
	preNode = NULL;
	nextNode = NULL;
	while (pHead != NULL)
	{
		nextNode = pHead->next;
		pHead->next = preNode;
		preNode = pHead;
		pHead = nextNode;
	}
	ListNode *ansNode = preNode;
	// while (ansNode != NULL)
	// {
	// 	cout << ansNode->val << endl;
	// 	ansNode = ansNode->next;
	// }
	return preNode;
}

int main(int argc, char const *argv[])
{
	int n = 10;
	ListNode *headNode;
	headNode->val = n;
	ListNode *tmpNode = headNode;
	cout << "1" << endl;
	while (n--)
	{
		ListNode *newNode;
		newNode->val = n;
		tmpNode->next = newNode;
		tmpNode = tmpNode->next;
	}
	cout << "2" << endl;
	// ReverseList(headNode);
	return 0;
}