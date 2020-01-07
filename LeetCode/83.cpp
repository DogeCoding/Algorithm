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

ListNode* deleteDuplicates(ListNode* head) {
	if (!head) return head;
	ListNode *ans = head;
	while (head) {
		cout << head->val << "   " << head->next->val << endl;
		if (head->val == head->next->val) {
			head->next = head->next->next;
		}
		head = head->next;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int a[5] = {1,1,2};
	ListNode *head = creatList(a, 3);
	ListNode *temp = deleteDuplicates(head);
	while (temp) {
		cout << temp->val << endl;
		temp = temp->next;
	}
	return 0;
}