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

int depth(TreeNode *root) {
	if (!root) return 0;
	int left = deep(root->left);
	if (left == -1) return -1;
	int right = deep(root->right);
	if (right == -1) return -1;
	return abs(left - right) < 2 ? max(left, right) + 1 : -1;
}

int depth(TreeNode *root) {
	if (!root) return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
	if (!root) return true;
	int left = depth(root->left);
	int right = depth(root->right);
	return abs(left - right) < 2 && isBalanced(root->left) && isBalanced(root->right);
}

int main(int argc, char const *argv[]) {
	
	return 0;
}