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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *step1 = head, *step2 = head;
	while (step1 != NULL) {
		if (n-- < 0) {
			step2 = step2 -> next;
		}
		step1 = step1 -> next;
	}
	if (n == 0) {
		head = head -> next;
	} else {
		step2->next = step2->next->next;
	}
	return head;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}