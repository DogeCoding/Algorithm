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

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	if (!matrix.size() || !matrix[0].size()) return false;
	int width = matrix[0].size();
	int length = matrix.size();
	for (int i = length - 1; i >= 0; i--) {
		if (target == matrix[i][0]) return true;
		if (target > matrix[i][0]) {
			for (int j = 1; j < width; j++) {
				if (target == matrix[i][j]) return true;
				if (target < matrix[i][j]) break;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}