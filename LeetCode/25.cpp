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

ListNode* reverseKGroup(ListNode* head, int k) {
	if (!head || !head->next) return head;
	ListNode *ans = new ListNode(0);
	ListNode *iteration = ans;
	ListNode *pre = NULL;
	ListNode *next = head->next;
	ListNode *temp = head;
	int i = 0;
	while (i < k) {
		iteration->next = new ListNode(head->val);
		iteration = iteration->next;
		if (!next) break;
		head->next = pre;
		pre = head;
		head = next;
		next = next->next;
		if (++i == k) {
			temp = head;
			i = 0;
		} 
	}
	if (i != k - 1) {
		iteration->next = temp;
	}
	return ans->next;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}