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

int findRepeatNumber(vector<int>& nums) {
	if (!nums.size()) return 0;
	sort(nums.begin(), nums.end());
	int prev = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == prev) {
			return prev;
		}
		prev = nums[i];
	}
	return 0;
}

int findRepeatNumber(vector<int>& nums) {
    unordered_map<int,int>m;
    for(int i=0;i<nums.size();i++){
        if(++m[nums[i]]>1) return nums[i];
    }
    return 0;
}
    

int main(int argc, char const *argv[])
{
	
	return 0;
}