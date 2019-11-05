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

ListNode* swapPairs(ListNode* head) {
	if (!head) return head;
	ListNode *tempHead = new ListNode(0);
	ListNode *ans = tempHead;
	tempHead->next = head;
	ListNode *left = head;
	ListNode *right = head->next;
	while (right) {
		ListNode *temp = right->next;
		right->next = left;
		left->next = temp;
		tempHead->next = right;
		tempHead = left;
		left = left->next;
		if (left) {
			right = left->next;
		} else {
			right = NULL;
		}
	}
	return ans->next;   
}

int main(int argc, char const *argv[])
{
	
	return 0;
}