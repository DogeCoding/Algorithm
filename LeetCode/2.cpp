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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ans = new ListNode(0);
    ListNode *tl1, *tl2, *head;
    tl1 = l1;
    tl2 = l2;
    head = ans;
    int carry = 0;
    while(tl1 || tl2) {
    	int x = tl1 ? tl1->val : 0;
    	int y = tl2 ? tl2->val : 0;
    	int temp = x + y + carry;
    	carry = temp / 10;
    	ans->next = new ListNode(temp%10);
    	ans = ans->next;
    	if (tl1) tl1 = tl1->next;
    	if (tl2) tl2 = tl2->next;
    }
    if (carry) {
    	ans->next = new ListNode(carry);
    	ans = ans->next;
    }
    return head->next;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}