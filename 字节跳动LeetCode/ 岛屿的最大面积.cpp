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
#include <string>

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

int maxAreaOfIsland(vector<vector<int>> &grid, int i, int j) {
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return 0;
	if (grid[i][j]) {
		grid[i][j] = 0;
		return 1 + maxAreaOfIsland(grid, i-1, j) + maxAreaOfIsland(grid, i, j-1) + maxAreaOfIsland(grid, i+1, j) + maxAreaOfIsland(grid, i, j+1);
	}
	return 0;
} 

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int ans = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j]) {
				int temp = maxAreaOfIsland(grid, i, j);
				ans = max(ans, temp); 
			}
		}
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	cout << reverseWords("the sky is blue") << endl;
	return 0;
}













