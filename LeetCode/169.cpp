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

int majorityElement(vector<int>& nums) {
	int target = nums.size() / 2;
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]]++;
		if (map[nums[i]] > target) {
			return nums[i];
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	vector<int> nums = {3,2,3};
	cout << majorityElement(nums) << endl;
	return 0;
}