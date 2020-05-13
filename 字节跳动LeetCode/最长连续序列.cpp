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

int longestConsecutive(vector<int>& nums) {
	if (!nums.size()) return 0;
	int temp = 1;
	int ans = 1;
	map<int, int> sortMap;
	for (int i = 0; i < nums.size(); i++) {
		sortMap[nums[i]] = 1;
	}
	bool first = true;
	int cmp = 0;
	for (map<int, int>::iterator i = sortMap.begin(); i != sortMap.end(); ++i) {
		if (first) {
			cmp = i->first;
			first = false;
			continue;
		}
		if (i->first - cmp == 1) {
			temp++;
			ans = max(ans, temp);
		} else {
			temp = 1;
		}
		cmp = i->first;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}