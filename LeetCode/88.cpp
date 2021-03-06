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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (!n) return;
	int tm = m, tn = n;
	vector<int> ans(n+m);
	int i = 0;
	while (tm && tn) {
		if (nums1[m-tm] < nums2[n-tn]) {
			ans[i++] = nums1[m-tm];
			tm--;
		} else {
			ans[i++] = nums2[n-tn];
			tn--;
		}
	}
	while (tm) {
		ans[i++] = nums1[m-tm--];
	}
	while (tn) {
		ans[i++] = nums2[n-tn--];
	}
	nums1 = ans;
}

int main(int argc, char const *argv[])
{
	vector<int> nums1 = {4,5,6,0,0,0};
	vector<int> nums2 = {1,2,3};
	merge(nums1, 3, nums2, 3);
	for (int i = 0; i < 6; i++) {
		cout << "  " << nums1[i];
	}
	cout << endl;
	return 0;
}