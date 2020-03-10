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

bool hasCycle(ListNode *head) {
	ListNode *point1 = head, *point2 = head;
	while (point1 && point2) {
		point2 = point2->next;
		if (!point2) return false;
		point2 = point2->next;
		if (!point2) return false;
		point1 = point1->next;
		if (point1 == point2) return true;
	}
	return false;

}

int main(int argc, char const *argv[])
{
	
	return 0;
}