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

int coinChange(vector<int>& coins, int amount) {
	if (amount <= 0 || !coins.size()) return 0;
	sort(coins.begin(), coins.end());
	int ans = 0;
	int target = amount;
	for (int i = coins.size() - 1; i >= 0; i--) {
		ans = target / coins[i];
		target = target % coins[i];
		if (!target) return ans;
		for (int j = i - 1; j >= 0; j--) {
			ans += target / coins[j];
			target = target % coins[j];
			if (!target) return ans;
		}
	}
	if (target != 0) return -1;
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}