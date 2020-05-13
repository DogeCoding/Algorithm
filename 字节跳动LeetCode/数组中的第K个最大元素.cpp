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

int findLengthOfLCIS(vector<int>& nums) {
	if (!nums.size()) return 0;
	vector<int> dp(nums.size(), 0);
	dp[0] = 1;
	int ans = 1;
	for (int i = 1; i < nums.size(); i++) {
		dp[i] = nums[i] > nums[i-1] ? dp[i-1] + 1 : 1;
		ans = max(dp[i], ans);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}