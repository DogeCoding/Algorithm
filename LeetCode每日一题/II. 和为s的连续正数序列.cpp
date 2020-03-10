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

vector<vector<int>> findContinuousSequence(int target) {
	int n = 2;
	vector<vector<int>> ans;
	while (1) {
		int a1 = (2 * target + n - pow(n, 2)) / (2 * n);
		int remainder = (2 * target + n - (int)pow(n, 2)) % (2 * n);
		if (a1 < 1) {
			vector<vector<int>> reversal;
			for (int i = ans.size() - 1; i >= 0; i--)
				reversal.push_back(ans[i]);
			return reversal;
		}
		if (remainder > 0) {
			n++;
			continue;
		}
		vector<int> temp;
		for (int i = 0; i < n; i++) {
			temp.push_back(a1 + i);
		}
		ans.push_back(temp);
		n++;
	}
	return ans;
}

vector<vector<int>> findContinuousSequence(int target) {
	int left = 1, right = 1;
	int sum = 0;
	vector<vector<int>> ans;
	while (left <= target / 2) {
		if (sum < target) {
			sum += right;
			right++;
		} else if (sum > target) {
			sum -= left;
			left++;
		} else {
			vector<int> temp;
			for (int i = left; i < right; i++) {
				temp.push_back(i);
			}
			ans.push_back(temp);
			sum -= left;
			left++;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}