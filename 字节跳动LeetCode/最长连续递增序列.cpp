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

int search(vector<int>& nums, int target) {
	if (!nums.size()) return -1;
	if (nums.size() == 1) return nums[0] == target ? 0 : -1;
	int l = 0, r = nums.size() - 1;
	while (l <= r) {
		int mid = (r + l) / 2;
		if (nums[mid] == target) return mid;
		if (nums[0] <= nums[mid]) {
			if (nums[0] <= target && target < nums[mid]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		} else {
			if (nums[mid] < target && target <= nums[nums.size() - 1]) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}