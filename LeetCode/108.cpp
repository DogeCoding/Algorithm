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

TreeNode *createTree(vector<int> nums, int left, int right) {
	if (left > right) return NULL;
	if (left == right) return new TreeNode(nums[left]);
	int mid = (left + right) >> 1;
	TreeNode *node = new TreeNode(nums[mid]);
	node->left = createTree(nums, left, mid - 1);
	node->right = createTree(nums, mid + 1, right);
	return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (!nums.size()) return NULL;
	return createTree(nums, 0, nums.size() - 1);
}

int main(int argc, char const *argv[]) {
	
	return 0;
}