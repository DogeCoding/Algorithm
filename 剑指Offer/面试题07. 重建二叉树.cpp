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

TreeNode* buildTree(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd) {
	if (pStart > pEnd || iStart > iEnd) return NULL;
	TreeNode *root = new TreeNode(preorder[pStart]);
	int i = iStart;
	while (inorder[i] != preorder[pStart]) {
		i++;
	}
	int npStart = pStart + 1;
	root->left = buildTree(preorder, npStart, npStart + i - iStart - 1, inorder, iStart, i - 1);
	root->right = buildTree(preorder, npStart + i - iStart, pEnd, inorder, i + 1, iEnd);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}