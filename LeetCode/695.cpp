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

int areaOfIsland(vector<vector<int>> &grid, int i, int j, int row, int column) {
	if (grid[i][j] == 1) {
		grid[i][j] = -1;
		return (i>0?areaOfIsland(grid,i-1,j,row,column):0)+(i<row-1?areaOfIsland(grid,i+1,j,row,column):0)+(j>0?areaOfIsland(grid,i,j-1,row,column):0)+(j<column-1?areaOfIsland(grid,i,j+1,row,column):0)+1;
	}
	return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int ans = 0;
	int row = grid.size();
	int column = row > 0 ? grid[0].size() : 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (grid[i][j] == 1) {
				int temp = areaOfIsland(grid, i, j, row, column);
				ans = max(temp, ans);
			}

		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> list = {0, 1};
	vector<vector<int>> lists;
	lists.push_back(list);
	cout << maxAreaOfIsland(lists) << endl;
	return 0;
}