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
	int k = 0;
	for (int i = 0; i < m + n; i++) {
		if (i >= m && nums1[i] == 0) {
			nums1[i] = nums2[k++];
		} else if (nums1[i] < nums2[k]) {
		} else {
			int temp = nums1[i];
			nums1[i] = nums2[k];
			nums2[k] = temp;
		}
		cout << nums1[i] << "  " << nums2[k] << endl;
	}
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