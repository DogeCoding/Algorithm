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

void quickSort(vector<int> &nums, int left, int right) {
	if (left >= right) return;
	int l = left, r = right, sentry = nums[l];
	while (l < r) {
		while (l < r && nums[r] > sentry) r--;
		nums[l] = nums[r];
		while (l < r && nums[l] < sentry) l++;
		nums[r] = nums[l];
	}
	nums[l] = sentry;
	quickSort(nums, left, l - 1);
	quickSort(nums, l + 1, right);
}

vector<int> sortArray(vector<int>& nums) {
	quickSort(nums, 0, nums.size());
	return nums;
}

int main(int argc, char const *argv[])
{
	vector<int> nums = {5,1,1,2,0,0};
	vector<int> ans = sortArray(nums);
	for (auto i : ans) {
		cout << i << endl;
	}
for (auto i : nums) {
		cout << i << endl;
	}	
	return 0;
}