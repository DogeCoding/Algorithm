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

// int lastRemaining(int n, int m) {
// 	vector <int> num;
// 	for (int i = 0; i < n; i++) num.push_back(i);
// 	int idx = 0;
// 	while(num.size() > 1) {
// 		idx = (idx + m - 1) % num.size();
// 		num.erase(num.begin() + idx);
// 	}
// 	return num[0];
// }

int lastRemaining(int n, int m) {
	int idx = 0;
	for (int i = 2; i <= n; i++) {
		idx = (idx + m) % i;
	}
	return idx;
}

int main(int argc, char const *argv[])
{
	cout << lastRemaining(5, 3) << endl;
	return 0;
}