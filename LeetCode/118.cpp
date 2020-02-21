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

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ans;
	if (numRows <= 0) return ans;
	ans.push_back({1});
	if (numRows == 1) return ans;
	ans.push_back({1,1});
	if (numRows == 2) return ans;
	for (int i = 3; i <= numRows; i++) {
		vector<int> temp = {};
		for (int j = 0; j < i; j++) {
			if (!j || j == i-1) {
				temp.push_back(1);
			} else {
				temp.push_back(ans[i-2][j-1] + ans[i-2][j]);
			} 
		}
		ans.push_back(temp);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}