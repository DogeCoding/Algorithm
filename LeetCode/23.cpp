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

 ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()) return NULL;
	ListNode *head = new ListNode(0);
	ListNode *ans = head;
	int index = 0;
	while(1) {
		bool isBreak = true;
		int min = 0x7fffff;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL) {
				if (lists[i]->val < min) {
					index = i;
					min = lists[i]->val;
				}
				isBreak = false;
			}
		}
		if (isBreak) {
			break;
		}
		ListNode *a = new ListNode(lists[index]->val);
		head->next = a;
		head = head->next;
		lists[index] = lists[index]->next;
	}
	head->next = NULL;
	return ans->next;     
}

int main(int argc, char const *argv[])
{
	
	return 0;
}