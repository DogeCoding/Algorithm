#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* creatList(int *list, int length) {
	ListNode *head = new ListNode(0);
	ListNode *ans = head;
	for (int i = 0; i < length; i++) {
		head->next = new ListNode(list[i]);
		head = head->next;
	}
	return ans->next;
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* reverseList(ListNode* head) {
	ListNode *prevNode = NULL;
	ListNode *currentNode = head;
	while (currentNode) {
		ListNode *nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	return prevNode;
}

ListNode* reverseList(ListNode* prev, ListNode* cur) {
	if (!cur) return prev;
	ListNode *next = cur->next;
	cur->next = prev;
	prev = cur;
	cur = next;
	return reverseList(prev, cur);
}

ListNode* reverseList(ListNode* head) {
	return reverseList(NULL, head);
}

int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	ListNode *head = creatList(a, 5);
	ListNode *ans = reverseList(head);
	while(ans) {
		cout << ans->val << endl;
		ans = ans->next;
	}
	return 0;
}