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

int massage(vector<int>& nums) {
	if (!nums.size()) return 0;
	int len = nums.size();
	vector<int> dp(len, 0);
	dp[0] = nums[0];
	if (len == 1) return dp[0];
	dp[1] = max(dp[0], nums[1]);
	for (int i = 2; i < len; i++) {
		dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
		// cout << "dp: " << i << " " << dp[i] << endl;
	}
	int ans = 0;
	for (auto num : dp) {
		ans = max(ans, num);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> a = {1,2,3,1};
	cout << massage(a) << endl;
	return 0;
}