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

// 迭代
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> ans;
	if (!root) return ans;
	queue<TreeNode *> queue;
	queue.push(root);
	while (!queue.empty()) {
		int qSize = queue.size();
		vector<int> level_ans;
		for (int i = 0; i < qSize; i++) {
			TreeNode *node = queue.front();
			queue.pop();
			level_ans.emplace_back(node->val);
			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);
		}
		ans.insert(ans.begin(), level_ans);
	}
	return ans;
}

// 递归
void dfs(vector<vector<int>> &res, TreeNode *node, int level) {
	if (!node) return;
	if (level >= res.size()) {
		vector<int> level_res;
		res.emplace_back(level_res);
	}
	res[level].emplace_back(node->val);
	dfs(res, node->left, level+1);
	dfs(res, node->right, level+1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> ans;
	dfs(ans, root, 0);
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}